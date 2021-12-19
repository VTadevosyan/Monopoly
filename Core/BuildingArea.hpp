/**
 * MONOPOLY
 */

#ifndef MONOPOLY_BUILDINGAREA_HPP
#define MONOPOLY_BUILDINGAREA_HPP

#include "Area.hpp"

#include "Monopoly/Monopoly.hpp"


namespace Core {

/// @class BuildingArea
/// @brief BuildingArea
class BuildingArea : public Area
{
public:
    /// @brief Constructor
    explicit BuildingArea(const size_t, const std::string&, const cash_t);

    /// @brief Destructor
    ~BuildingArea() = default;

public:
    /// @brief Sets the price for current building area
    void setPrice(const cash_t) noexcept;

    /// @brief Gets the price for current building area
    cash_t getPrice() const noexcept;

private:
    cash_t mPrice;
};

} /// Core namespace

#endif // MONOPOLY_BUILDINGAREA_HPP
