/*! @file
 * @brief Represents an Enigma Machine Plugboard
 */

#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <array>

/*! @class
 * @brief Plugboard of the Enigma machine.
 *
 * Prior to translation by the Rotor mechanism, swaps pairs of characters.
 */
class Plugboard {
public:
    /*!
     * @brief construct a Plugboard which performs no swaps.
     */
    Plugboard();

    /*! @brief Add a wire to the plugboard to swap two characters.
     *
     * @param start first character to swap (or start of a wire)
     * @param end second character to swap (or end of a wire)
     */
    void add_wire(char start, char end);

    /*! @brief Remove a wire (or character swap pair) from the plugboard.
     *
     * @param start start of the wire which is to be removed
     * @param end end of the wire which is to be removed
     */
    void remove_wire(char start, char end);

    /*! @brief Translate a character through the Plugboard
     *
     * @param input character to translate through the plugboard
     * @return translated character, which has potentially
     *         been swapped with another character
     */
    [[nodiscard]] char translate(char input) const;

    /*!
     * @brief clear all wires from the plugboard, returning it to
     *  its default state.
     */
    void clear_wires();

private:
    std::array<char, 26> wires{};
};

#endif //PLUGBOARD_H
