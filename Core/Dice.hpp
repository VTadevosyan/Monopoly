/**
 * MONOPOLY
 */

#ifndef MONOPOLY_DICE_HPP
#define MONOPOLY_DICE_HPP

#include <utility>


namespace Core {

/// @class Dice
/// @brief Dice
class Dice
{
public:
    using result_t = std::pair<int, int>;

public:
    /// @brief Rolls a dices and gets the result
    static result_t rollDices() noexcept;

public:
    /// @brief Constructor
    Dice();

    /// @brief Destructor
    ~Dice() = default;

public:
    /// @brief Roll a dice and return generated value
    int roll() const noexcept;

};

} /// Core namespace

#endif // MONOPOLY_DICE_HPP
