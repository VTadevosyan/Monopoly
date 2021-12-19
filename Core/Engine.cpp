/**
 * MONOPOLY
 */

#include "Board.hpp"
#include "BuildingArea.hpp"
#include "ColorGroup.hpp"
#include "Engine.hpp"
#include "EventArea.hpp"
#include "Jail.hpp"

#include <cassert>


namespace Core {

Engine::Engine()
{
    mBoard = new Board;
    mColorGroup = new ColorGroup;
}

Engine::~Engine()
{
    if (mBoard != nullptr) {
        delete mBoard;
        mBoard = nullptr;
    }
}

cash_t Engine::getBuildingPrice(size_t index) const noexcept
{
    assert(index <= BOARD_ITEMS_COUNT);
    Area* area = mBoard->getArea(index).get();
    /// TODO ASSERT
    if (area->getType() != Area::Type::Building) {
        return 0;
    }
    return static_cast<BuildingArea*>(area)->getPrice();
}

ColorGroup* Engine::getColorGroup() const noexcept
{
    assert(mColorGroup != nullptr);
    return mColorGroup;
}


} /// Core namespace
