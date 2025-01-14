/*! @file
* @brief Math utilities, mainly functions for working with "wrapping" arithmetic.
 */

#ifndef MATH_HELPER_H
#define MATH_HELPER_H

/*! @namespace
 * @brief Functions for working with "wrapping" arithmetic.
 */
namespace WrappedMath {
 /*! @brief Subtract one int from another, wrapping around if
  * the result falls outside a given range.
  *
  * @param lhs left hand side of the subtraction
  * @param rhs right hand side of the subtraction
  * @param mod modulus for the "wrapping"
  * @return result of the subtraction, will be between 0 and mod (inclusive).
  */
 int subtract(int lhs, int rhs, int mod);
 /*! @brief Add two numbers together, wrapping around if
 * the result falls outside a given range.
 *
 * @param lhs left hand side of the addition
 * @param rhs right hand side of the addition
 * @param mod modulus for the "wrapping"
 * @return result of the addition, will be between 0 and mod (inclusive).
 */
int add(int lhs, int rhs, int mod);
}

#endif //MATH_HELPER_H
