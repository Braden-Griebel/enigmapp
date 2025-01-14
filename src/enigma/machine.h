/*! @file
 * @brief Representation of an enigma machine.
*/

#ifndef MACHINE_H
#define MACHINE_H

#include <array>
#include <cctype>
#include <sstream>


#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"

/*! @class Machine
 * @brief A representation of an enigma machine.
 *
 * Enigma machine including a plugboard, 3 rotors, and a reflector.
 * Can encode
 */
class Machine {
    /*! @brief Array of Enigma machine rotors.
     * @see Rotor
     *
     * Includes three rotors, which characters are translated through
     * in sequence (then translated back through in reverse order).
     * Following the translation of each character,
     * the last rotor will be stepped (or advanced), and if it steps
     * past a notch the rotor to its left will also be stepped.
    */
    std::array<Rotor, 3> rotors;
    /*! @brief Enigma machine reflector.
     * @see Reflector
     * Similar to the rotors, translates characters
    */
    Reflector reflector;
    /*! @brief Enigma machine plugboard
     *  @see Plugboard
     * Prior to translation by the rotors, characters are passed through
     * this plugboard which can swap pairs of characters.
     */
    Plugboard plugboard;

public:
    /*! @brief Construct Enigma Machine based on rotors numbers (selecting 1-8), and
     * a reflector (selected by a-c).
     * @param rotor1 first rotor selected, values can be 1-8
     * @param rotor1 second rotor selected, values can be 1-8
     * @param rotor1 third rotor selected, values can be 1-8
     * @param reflector reflector, values can be a,b, or c
     */
    Machine(const int rotor1, const int rotor2, const int rotor3, const char reflector): rotors({
            Rotor(rotor1),
            Rotor(rotor2), Rotor(rotor3)
        }),
        reflector(reflector) {
    };

    /*! @brief Change the ring settings of the rotors
     *
     * @param rotor1 Ring setting for the first rotor, values can be a-z
     * @param rotor2 Ring setting for the second rotor, values can be a-z
     * @param rotor3 Ring setting for the third rotor, values can be a-z
     */
    void set_rotors(char rotor1, char rotor2, char rotor3);

    /*! @brief Change the ring setting of the reflector
     *
     * @param reflector ring setting for the reflector, values can be a-z
     */
    void set_reflector(char reflector);

    /*! @brief Set the plugboard configuration
     *
     * @param plugboard_configuration configuration of the plugboard,
     * should be a comma seperated list of wire connections, where each
     * wire connection is two characters to swap seperated by a
     * dash, e.g. a-n,d-s,q-p (no spaces).
     */
    void set_plugboard(const std::string& plugboard_configuration);

    /*! @brief Translate (or encode) a message using the Enigma machine.
     *
     * @param input Message to encode
     * @return Translated/encoded message
     */
    std::string translate(const std::string& input);
};


#endif //MACHINE_H
