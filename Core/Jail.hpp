/**
 * MONOPOLY
 */

#ifndef MONOPOLY_JAIL_HPP
#define MONOPOLY_JAIL_HPP

#include "Area.hpp"


namespace Core {

/// @class Jail
/// @brief Jail
class Jail : public Area
{
public:
    /// @brief Constructor
    explicit Jail(const size_t);

    /// @brief Destructor
    ~Jail() = default;
};

} /// Core namespace

#endif // MONOPOLY_JAIL_HPP
