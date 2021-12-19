/**
 * MONOPOLY
 */

#ifndef MONOPOLY_ENGINE_HPP
#define MONOPOLY_ENGINE_HPP

#include "Monopoly/Monopoly.hpp"


namespace Core {

class Board;
class ColorGroup;

/// @class Engine
/// @brief Engine
class Engine
{
public:
    /// @brief Constructor
    Engine();

    /// @brief Destructor
    ~Engine();

public:
    /// @brief Gets the specified building area's price
    /// XXX return 0, if specified area isn't building
    /// TODO CHANGE TO ASSERT
    cash_t getBuildingPrice(size_t) const noexcept;

    /// @brief Gets the color group
    ColorGroup* getColorGroup() const noexcept;

private:
    Board* mBoard = nullptr;
    ColorGroup* mColorGroup = nullptr;
};

} /// Core namespace

#endif /// MONOPOLY_ENGINE_HPP
