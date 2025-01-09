//
// Created by bgriebel on 1/8/25.
//

#ifndef ROTOR_H
#define ROTOR_H

#include <array>
#include <string>
#include <unordered_set>


class Rotor {
    std::array<char, 26> rotor_array_forward;
    std::array<char, 26> rotor_array_reverse;
    int offset;
    std::unordered_set<char> notches;

public:
    explicit Rotor(const std::string& rotor_config, const std::string& notch_config);

    void set_offset(int offset_setting);

    bool advance();

    [[nodiscard]] char translate_forward(char char_in) const;

    [[nodiscard]] char translate_reverse(char char_in) const;
};

#endif //ROTOR_H
