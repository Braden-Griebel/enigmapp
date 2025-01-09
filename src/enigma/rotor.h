//
// Created by bgriebel on 1/8/25.
//

#ifndef ROTOR_H
#define ROTOR_H

#include <array>


class Rotor {
    std::array<char, 26> rotor_array_forward;
    std::array<char, 26> rotor_array_reverse;
    int offset;

public:
    explicit Rotor(std::array<char, 26> rotor_array);

    void advance();

    [[nodiscard]] char translate_forward(char char_in) const;

    [[nodiscard]] char translate_reverse(char char_in) const;
};

#endif //ROTOR_H
