/**
 * MONOPOLY
 */

#ifndef MONOPOLY_BOARD_HPP
#define MONOPOLY_BOARD_HPP

#include "Monopoly/Monopoly.hpp"

#include <vector>
#include <memory>


namespace Core {

class Area;

/// @class Board
/// @brief Board
class Board
{
public:
    /// @brief Constructor
    Board();

    /// @brief Destructor
    ~Board();

public:
    std::shared_ptr<Area> getArea(const size_t) const;

public:
    /// @brief returns true if specified area is building area, false - otherwise
    bool isBuilding(const size_t) const;

    /// @brief returns true if specified area is event area, false - otherwise
    bool isEvent(const size_t) const;

    /// @brief returns true if specified area is jail, false - otherwise
    bool isJail(const size_t) const;

private:
    void initialize();

private:
    std::vector<std::shared_ptr<Area>> mData;
};

} /// Core namespace

#endif // MONOPOLY_BOARD_HPP
