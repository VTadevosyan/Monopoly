/**
 * MONOPOLY
 */

#include "Board.hpp"
#include "BuildingArea.hpp"
#include "Event.hpp"
#include "EventArea.hpp"
#include "Jail.hpp"

#include <cassert>


namespace Core {

Board::Board()
{
    initialize();
}

Board::~Board()
{
    for (auto it : mData) {
        it.reset();
    }
}

void Board::initialize()
{
    size_t index = 0;
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::Start)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Onex", 600)));
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::Chance)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Globbing", 600)));
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::Tax)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Yerevan Mall", 2000)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "UTaxi", 1000)));
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::Tax)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Yandex GO", 1000)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "GG", 1200)));
    mData.push_back(std::shared_ptr<Jail>(new Jail(index++)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "IDram", 1400)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Tucan Textile", 1500)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "EasyPay", 1400)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "TelCell", 1600)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Dalma Garden Mall", 2000)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Zangi", 1800)));
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::Chance)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "PicsArt", 1800)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Krisp", 2000)));
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::FreeParking)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Beeline Armenia", 2200)));
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::Chance)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "UCOM", 2200)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "MTS Armenia", 2400)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Rossia Mall", 2000)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Tsiran", 2600)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Nor Zovq", 2600)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Alex Textile", 1500)));
    //mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::Chance)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Yerevan City", 2800)));
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::GoToJail)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Veolia Jur", 3000)));
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::Chance)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Gazprom Armenia", 3000)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Hayastani Elektrakan Cancer", 3200)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "MegaMall", 2000)));
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::Tax)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Noy", 3500)));
    mData.push_back(std::shared_ptr<EventArea>(new EventArea(index++, Event::Type::Chance)));
    mData.push_back(std::shared_ptr<BuildingArea>(new BuildingArea(index++, "Ararat", 4000)));
}

std::shared_ptr<Area> Board::getArea(const size_t index) const
{
    assert(index <= BOARD_ITEMS_COUNT);
    return mData[index];
}

bool Board::isBuilding(const size_t index) const
{
    assert(index <= BOARD_ITEMS_COUNT);
    return mData[index]->getType() == Area::Type::Building;
}

bool Board::isEvent(const size_t index) const
{
    assert(index <= BOARD_ITEMS_COUNT);
    return mData[index]->getType() == Area::Type::Event;
}

bool Board::isJail(const size_t index) const
{
    assert(index <= BOARD_ITEMS_COUNT);
    return mData[index]->getType() == Area::Type::Jail;
}



} /// Core namespace
