//
// Created by bgriebel on 1/8/25.
//

#include "machine.h"

void Machine::set_rotors(const char rotor1, const char rotor2, const char rotor3) {
    this->rotors[0].set_offset(rotor1-'a');
    this->rotors[1].set_offset(rotor2-'a');
    this->rotors[2].set_offset(rotor3-'a');
}

void Machine::set_reflector(const char reflector) {
    this->reflector.set_offset(reflector-'a');
}

void Machine::set_plugboard(const std::string& plugboard_configuration) {
    // First clear the old configuration
    this->plugboard.clear_wires();

    // Create a stream from the configuration to make splitting the text easier
    std::stringstream ss(plugboard_configuration);
    std::string wire_pair;
    constexpr char delim = ',';

    while (std::getline(ss, wire_pair, delim)) {
        if (wire_pair.length() != 3){
            throw std::invalid_argument("Invalid plugboard configuration");
        }
        const char wire_start = std::tolower(wire_pair[0]);
        const char wire_end = std::tolower(wire_pair[2]);

        this->plugboard.add_wire(wire_start, wire_end);
    }
}

std::string Machine::translate(const std::string& input) {
    std::string output;
    // The output length should be at most the length of the input
    output.reserve(input.length());
    for (const char& current_char: input) {
        // Just skip translation for all non-alphabetic characters
        if ((current_char<='z' && current_char>='a')||
            (current_char<='Z' && current_char>='A')) {
            char translating_char = std::tolower(current_char);
            // Start with plugboard
            translating_char = this->plugboard.translate(translating_char);
            // Then step through all the rotors forward
            for (const auto& rotor : this->rotors) {
                translating_char = rotor.translate_forward(translating_char);
            }
            // Through the reflector
            translating_char = this->reflector.translate(translating_char);
            // Back through the rotors in reverse (could be made more concise with ranges in c++20)
            for (int idx = 2; idx >= 0; idx--) {
                translating_char  = this->rotors[idx].translate_reverse(translating_char);
            }
            // Back through the plugboard
            translating_char = this->plugboard.translate(translating_char);
            // Append it to the output
            output.push_back(translating_char);
            // Now step all the rotors
            bool should_step = true;
            for (auto rotor_idx = 2; rotor_idx >= 0; rotor_idx--) {
                if (should_step) {
                    should_step = rotors.at(rotor_idx).advance();
                } else {
                    should_step = false;
                }
            }
        } else {
            output.push_back(current_char);
        }
    }
    return output;
}


