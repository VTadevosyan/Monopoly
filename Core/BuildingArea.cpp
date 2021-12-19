/**
 * MONOPOLY
 */

#include "BuildingArea.hpp"

#include <QtGlobal>


namespace Core {

BuildingArea::BuildingArea(const size_t index, const std::string& label, const cash_t price)
    : Area(index, Area::Type::Building, label)
    , mPrice(price)
{
    Q_ASSERT(!label.empty());
}

void BuildingArea::setPrice(const cash_t c) noexcept
{
    mPrice = c;
}

/// @brief Gets the price for current building area
cash_t BuildingArea::getPrice() const noexcept
{
    return mPrice;
}

} /// Core namespace
