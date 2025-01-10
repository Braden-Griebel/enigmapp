//
// Created by bgriebel on 1/8/25.
//

#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <array>
#include <cctype>
#include <string>

class Reflector {
    std::array<char, 26> reflector_array;
    int offset;
    static std::string reflector_config_from_char(char reflector);

    public:
      explicit Reflector(std::string configuration);
      explicit Reflector(const char reflector):Reflector(reflector_config_from_char(reflector)){}
      void set_offset(const int new_offset) {this->offset = new_offset;};
      [[nodiscard]] char translate(char c) const;
};

#endif //REFLECTOR_H
