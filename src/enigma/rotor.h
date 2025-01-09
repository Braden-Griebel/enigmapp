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
    std::unordered_set<char> notches;
    int offset;

    std::string wheel_config_from_wheel_number(int wheel_number);

    std::string wheel_notches_from_wheel_number(int wheel_number);

public:
    explicit Rotor(const std::string &rotor_config, const std::string &notch_config);

    explicit Rotor(const int wheel_number): Rotor(wheel_config_from_wheel_number(wheel_number),
                                            wheel_notches_from_wheel_number(wheel_number)) {
    };

    void set_offset(int offset_setting);

    bool advance();

    [[nodiscard]] char translate_forward(char char_in) const;

    [[nodiscard]] char translate_reverse(char char_in) const;
};

#endif //ROTOR_H
