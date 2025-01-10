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
    return 'a'+(reflector_array[(c-'a'+offset)%26]+offset);
}

std::string Reflector::reflector_config_from_char(const char reflector) {
    switch (reflector) {
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