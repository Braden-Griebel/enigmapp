/*!@file
 * @brief Represents an Enigma machine reflector
 */

#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <array>
#include <cctype>
#include <string>

#include "math_helper.h"

/*! @class
 * @brief Reflector of Enigma Machine
 */
class Reflector {
    /*!
     * @brief Character array representing the wiring of the Reflector.
     */
    std::array<char, 26> reflector_array;
    /*!
     * @brief representation of the ring setting of the Reflector
     */
    int offset;

    /*! @brief Get a reflector configuration from a reflector
     * specified by a character, a,b, or c.
     *
     * @param reflector_choice choice of reflector, either a, b, or c
     * @return string representation of the reflector configuration.
     */
    static std::string reflector_config_from_char(char reflector_choice);

    public:
    /*! @brief Construct a reflector based on a passed string configuration.
     *
     * @param configuration Configuration of the reflector represented by a
     * string. Represents wires of the reflector, aligns the configuration
     * with the alphabet, so 'a' will translate to the first character,
     * 'b' to the second, etc.
     */
    explicit Reflector(std::string configuration);

    /*! @brief Construct a reflector based on a character specification.
     *
     * @param reflector_selection choice of reflector, can be a, b, or c.
     */
    explicit Reflector(const char reflector_selection):Reflector(reflector_config_from_char(reflector_selection)){}
    /*! @brief Set the offset (or ring setting) of the Reflector.
     *
     * @param new_offset offset (or ring setting) to set.
     */
    void set_offset(const int new_offset) {this->offset = new_offset;};

    /*! @brief Translate a character through the reflector
     *
     * @param c character to translate through the reflector
     * @return translated character
     */
    [[nodiscard]] char translate(char c) const;
};

#endif //REFLECTOR_H
