/**
 * MONOPOLY
 */

#ifndef MONOPOLY_EVENT_HPP
#define MONOPOLY_EVENT_HPP



namespace Core {

/// @class Event
/// @brief Event
class Event
{
public:
    enum class Type
    {
        Start = 0,
        FreeParking,
        GoToJail,
        Tax,
        Chance
    };
};

} /// Core namespace

#endif /// MONOPOLY_EVENT_HPP
