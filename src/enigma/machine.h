//
// Created by bgriebel on 1/8/25.
//

#ifndef MACHINE_H
#define MACHINE_H

#include <array>
#include <cctype>
#include <sstream>


#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"

class Machine {
    std::array<Rotor, 3> rotors;
    Reflector reflector;
    Plugboard plugboard;

public:
    Machine(const int rotor1, const int rotor2, const int rotor3, const char reflector): rotors({
            Rotor(rotor1),
            Rotor(rotor2), Rotor(rotor3)
        }),
        reflector(reflector) {
    };

    void set_rotors(char rotor1, char rotor2, char rotor3);

    void set_reflector(char reflector);

    void set_plugboard(const std::string& plugboard_configuration);

    std::string translate(std::string input);
};


#endif //MACHINE_H
