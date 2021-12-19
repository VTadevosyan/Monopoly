/**
 * MONOPOLY
 */

#ifndef MONOPOLY_MANAGER_HPP
#define MONOPOLY_MANAGER_HPP

#include "Monopoly.hpp"

#include <string>
#include <vector>


namespace Core {

class Player;

}

namespace Monopoly {

/// @class Manager
/// @brief Singleton class for game manager
class Manager
{
public:
    /// @brief Gets the manager if exists or creates a new one
    static Manager* get();

private:
    static std::vector<color_t> PlayerColors;

public:
    /// @brief Checks if game can be launched or not
    bool canLaunchGame() const;

    /// @brief Gets the registered players count
    size_t playersCount() const;

    /// @brief Checks if game has registered players or not
    bool hasRegisteredPlayers() const;

    /// @brief Add player
    void registerPlayer(const std::string&);

    /// @brief Finds a player with given name
    Core::Player* findPlayer(const std::string&) const;

    /// @brief Finds a player with index
    Core::Player* findPlayer(const size_t) const;

private:
    Core::Player* createPlayer(const std::string&);
    color_t getCorrespondingPlayersColor() const;

private:
    /// @brief Constructor
    Manager();

    /// @brief Destructor
    ~Manager();

private:
    std::vector<Core::Player*> mPlayers;

};

} /// Monopoly namespace

#endif // MONOPOLY_MANAGER_HPP
