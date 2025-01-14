//
// Created by bgriebel on 1/8/25.
//

#include "reflector.h"

Reflector::Reflector(std::string configuration) {
    int idx = 0;
    for (const char c : configuration) {
        reflector_array[idx] = std::tolower(c);
        ++idx;
    }
    offset = 0;
}

char Reflector::translate(const char c) const {
    auto input_position = c-'a';
    auto raw_output_position = WrappedMath::add(input_position, offset, 26);
    auto raw_output = reflector_array.at(raw_output_position)-'a';
    auto output_position = WrappedMath::subtract(raw_output, offset, 26);
    auto output_char = 'a' +output_position;
    return output_char;
    //return 'a' + WrappedMath::subtract(reflector_array.at(WrappedMath::add( c-'a', offset, 26)), offset, 26);
}

std::string Reflector::reflector_config_from_char(const char reflector_choice) {
    switch (reflector_choice) {
        case 'a':
            return "EJMZALYXVBWFCRQUONTSPIKHGD";
        case 'b':
            return "YRUHQSLDPXNGOKMIEBFZCWVJAT";
        case 'c':
            return "FVPJIAOYEDRZXWGCTKUQSBNMHL";
        default:
            return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    }
}