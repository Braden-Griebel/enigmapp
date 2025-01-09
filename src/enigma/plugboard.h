//
// Created by bgriebel on 1/8/25.
//

#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <array>

class Plugboard {
  public:
    Plugboard();
    void add_wire(char start, char end);
    void remove_wire(char start, char end);
    [[nodiscard]] char translate(char input) const;
private:
    std::array<char, 26> wires{};
};

#endif //PLUGBOARD_H
