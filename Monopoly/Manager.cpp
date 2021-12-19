/**
 * MONOPOLY
 */

#include "Core/Dice.hpp"
#include "Core/Manager.hpp"
#include "Core/Player.hpp"

/// XXX
#include "Gui/IconManager.hpp"

#include "Monopoly/Manager.hpp"

#include <algorithm>
#include <functional>

namespace Monopoly {

std::vector<color_t> Manager::PlayerColors = {
    color_t::red,
    color_t::green,
    color_t::blue,
    color_t::yellow,
    color_t::magenta
};

Manager* Manager::get()
{
    static Manager m;
    return &m;
}

Manager::Manager()
{
    Core::Manager::create();
    Gui::IconManager::create();
}

Manager::~Manager()
{
    Core::Manager::destroy();
    Gui::IconManager::destroy();
}

size_t Manager::playersCount() const
{
    return mPlayers.size();
}

bool Manager::hasRegisteredPlayers() const
{
    return !mPlayers.empty();
}

bool Manager::canLaunchGame() const
{
    const size_t pc = playersCount();
    return pc >= MIN_PLAYERS_COUNT && pc <= MAX_PLAYERS_COUNT;
}

void Manager::registerPlayer(const std::string& name)
{
    if (playersCount() > MAX_PLAYERS_COUNT) {
        /// TODO throw
        return;
    }
    Core::Player* p = createPlayer(name);
    mPlayers.push_back(p);
}

Core::Player* Manager::findPlayer(const std::string& name) const
{
    std::function<bool(Core::Player*)> finder = [&name] (Core::Player* p) {
        return p->getName() == name;
    };
    auto playerIter = std::find_if(mPlayers.begin(), mPlayers.end(), finder);
    return playerIter != mPlayers.end() ? *playerIter : nullptr;
}

Core::Player* Manager::findPlayer(const size_t index) const
{
    if (index >= playersCount()) {
        return nullptr;
    }
    return mPlayers[index];
}

Core::Player* Manager::createPlayer(const std::string& name)
{
    Core::Player* player = new Core::Player(name);
    player->setColor(getCorrespondingPlayersColor());
    return player;
}

color_t Manager::getCorrespondingPlayersColor() const
{
    return PlayerColors[playersCount()];
}

} /// Monopoly namespace
