/**
 * MONOPOLY
 */

#ifndef MONOPOLY_MANAGER_HPP
#define MONOPOLY_MANAGER_HPP


namespace Monopoly {

/// @class Manager
/// @brief Singleton class for game manager
class Manager
{
public:
    /// @brief Gets the manager if exists or creates a new one
    static Manager* get();

private:
    /// @brief Constructor
    Manager();

    /// @brief Destructor
    ~Manager() = default;
};

} /// Monopoly namespace

#endif // MONOPOLY_MANAGER_HPP
