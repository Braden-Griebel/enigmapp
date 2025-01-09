//
// Created by bgriebel on 1/8/25.
//

#include <array>

#include "rotor.h"

// Constructors
Rotor::Rotor(std::string wheel_config, std::string notch_config) {
    int idx = 0;
    for (char c : wheel_config) {
        rotor_array_forward[idx] = c;
        rotor_array_reverse[c-'a'] = 'a'+idx;
        idx++;
    }
    for (char c : notch_config) {
        notches.insert(c);
    }
    offset = 0;
}


bool Rotor::advance() {
    char prev = 'a' + offset;
    offset = (offset+1)%26;
    if (notches.count(prev)) {
        return true;
    }
    return false;
}

void Rotor::set_offset(int offset_setting) {
    offset = offset_setting;
}


char Rotor::translate_forward(const char char_in) const {
    return 'a'+(rotor_array_forward[(char_in - 'a' + offset)%26]-'a'+offset)%26;
}

char Rotor::translate_reverse(const char char_in) const {
    return 'a'+(rotor_array_reverse[(char_in - 'a' + offset)%26]-'a'+offset)%26;
}
