#ifndef C_H
#define C_H

#include <assert.h>
#include <cstring>
#include <iostream>
#include <cstddef>

/**
 * @file C.h
 * @brief Small utility/test class used to exercise container semantics.
 *
 * The class wraps a single @c size_t value and provides copy/move
 * construction and assignment. Useful for verifying copy/move behavior
 * in custom containers (e.g., vector).
 */

/**
 * @class C
 * @brief Trivial wrapper around a @c size_t with copy/move semantics.
 *
 * Designed primarily for testing: Can instrument this class further
 * (e.g., add counters/logging) to observe when copies or moves occur in
 * container implementation.
 */
class C {
private:
  size_t value;  ///< Stored value

public:
  /**
   * @brief Construct with an initial value.
   * @param v Initial value (defaults to 0).
   */
  C(size_t v = 0);

  /**
   * @brief Copy constructor.
   * @param other Source instance to copy from.
   */
  C(const C &other);

  /**
   * @brief Move constructor.
   * @param other Source instance to move from.
   *
   * @note After a move, @p other is left in a valid but unspecified state.
   */
  C(C &&other)noexcept;

  /**
   * @brief Copy assignment.
   * @param other Source instance to copy from.
   * @return Reference to *this.
   */
  C &operator=(const C &other);

  /**
   * @brief Move assignment.
   * @param other Source instance to move from.
   * @return Reference to *this.
   *
   * @note Marked @c noexcept to help containers optimize move paths.
   */
  C &operator=(C &&other) noexcept;

  /**
   * @brief Destructor (trivial).
   */
  ~C();

  /**
   * @brief Get the stored value.
   * @return The wrapped @c size_t.
   *
   * @note Non-const by your current signature; make it @c const if you
   *       want to call it on const objects: @code size_t get_val() const; @endcode
   */
  size_t get_val();
};

#include "./Details/C.cpp"
#endif
