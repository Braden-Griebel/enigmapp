//
// Created by bgriebel on 1/8/25.
//

#include <array>

#include "rotor.h"

void Rotor::advance() {
    offset++;
}

char Rotor::translate_forward(const char char_in) const {
    // Translate char_in into a position on the rotor
    int in_pos = ((char_in - 'a') + offset)%26;

    // Translate the character through the rotor
    char char_out_raw = rotor_array_forward[in_pos];

    // Translate output character into a position,
    // taking into account the offset
    int out_pos = ((char_out_raw - 'a') + offset)%26;

    // Translate the output position (including the offset) to a character
    return 'a' + out_pos;
}
