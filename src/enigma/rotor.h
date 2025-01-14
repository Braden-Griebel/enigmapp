/*! @file
 * @brief Represents an Enigma Machine Rotor
 */

#ifndef ROTOR_H
#define ROTOR_H

#include <array>
#include <cctype>
#include <string>
#include <unordered_set>

#include "math_helper.h"

/*! @class
 * @brief Rotor of an Enigma Machine
 */
class Rotor {
    /*!
     * @brief Array representing the wire configuration of
     *   the Rotor, when the translation is moving forward
     *   (from left to right).
     */
    std::array<char, 26> rotor_array_forward;
    /*!
     * @brief Array representing the wire configuration of the
     *      Rotor, when the translation is moving in reverse
     *      (from right to left).
     */
    std::array<char, 26> rotor_array_reverse;
    /*!
     * @brief notches of the rotor, which characters will cause
     * the next Rotor (to the left) to advance when stepped past.
     */
    std::unordered_set<char> notches;
    /*!
     * @brief Offset of the wheel, represents the ring setting.
     */
    int offset;

    /*! @brief Get the Rotor configuration based on selecting a
     * preexisting rotor
     *
     * @param wheel_number number of the desired rotor, values can be 1-8.
     * @return Rotor configuration as a string.
     */
    static std::string wheel_config_from_wheel_number(int wheel_number);

    /*! @brief Get the notches of the Rotor based on selecting a
     *  preexisting rotor.
     *
     * @param wheel_number number of the desired rotor, values can be 1-8.
     * @return Rotor notches as a string.
     */
    std::string wheel_notches_from_wheel_number(int wheel_number);

public:
    /*!@brief construct a rotor from configuration strings
     *
    * @param rotor_config Configuration of the rotor represented by a
     * string. Represents wires of the reflector, aligns the configuration
     * with the alphabet, so 'a' will translate to the first character,
     * 'b' to the second, etc.
     * @param notch_config configuration of the notches represented by a string.
     * All the characters in the string will be interpreted as a notch, when the
     * rotor advances past those characters, it will step the wheel to its left.
     */
    explicit Rotor(const std::string &rotor_config, const std::string &notch_config);

    /*! @brief Construct a preexisting rotor/notch configuration selected by a number
     *
     * @param wheel_number which rotor configuration to use, values can be 1-8.
     */
    explicit Rotor(const int wheel_number): Rotor(wheel_config_from_wheel_number(wheel_number),
                                                  wheel_notches_from_wheel_number(wheel_number)) {
    };

    /*! @brief Set the offset/ring setting of the Rotor
     *
     * @param offset_setting offset/ring setting to set, a value from 0-25
     * which will be interpreted as a character.
     */
    void set_offset(int offset_setting);

    /*! @brief Get the current offset/ring setting of the rotor as an int
     *
     * @return current offset/ring setting as an int between 0 and 25, with
     * 0 representing a ring setting of 'a', and 25 representing a ring setting of 'z'.
     */
    int get_offset() const { return this->offset; };

    /*! Advance the rotor one position
     *
     * @return true if a notch was stepped past, so that the
     *  neighboring rotor to the left should be stepped, and false
     *  otherwise.
     */
    bool advance();

    /*! @brief Translate a character through the rotor when translating
     * forward (from left to right).
     *
     * @param char_in character to translate
     * @return translated character
     */
    [[nodiscard]] char translate_forward(char char_in) const;

    /*! @brief Translate a character through the rotor when translating
     * backwards (from right to left).
     *
     * @param char_in character to translate
     * @return translated character
     */
    [[nodiscard]] char translate_reverse(char char_in) const;
};

#endif //ROTOR_H
