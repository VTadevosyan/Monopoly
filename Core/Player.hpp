/**
 * MONOPOLY
 */

#ifndef MONOPOLY_PLAYER_HPP
#define MONOPOLY_PLAYER_HPP

#include "Monopoly/Monopoly.hpp"

#include <string>


namespace Core {

/// @class Player
/// @brief Player
class Player
{
public:
    /// @brief Constructor
    Player(const std::string&);

    /// @brief Destructor
    ~Player() = default;

public:
    /// @brief Gets the name of player
    std::string getName() const noexcept;

    /// @brief Gets the cash of player
    cash_t getCash() const noexcept;

    /// @brief Add cash to player
    void addCash(const cash_t);

    /// @brief Withdraw cash from player
    void withdrawCash(const cash_t);

    /// @brief Sets the player's color
    void setColor(const color_t) noexcept;

    /// @brief Gets the player's color
    color_t getColor() const noexcept;

    /// @brief Bankrupts player
    void bankrupt();

    /// @brief Checks if current player is active or not
    bool isActive() const noexcept;

private:
    std::string mName;
    cash_t mCash;
    color_t mColor;
    bool mIsActive;
};

} /// Core namespace

#endif // MONOPOLY_PLAYER_HPP
