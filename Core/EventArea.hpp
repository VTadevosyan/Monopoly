/**
 * MONOPOLY
 */

#ifndef MONOPOLY_EVENTAREA_HPP
#define MONOPOLY_EVENTAREA_HPP

#include "Area.hpp"
#include "Event.hpp"


namespace Core {

/// @class EventArea
/// @brief EventArea
class EventArea : public Area
{
public:
    /// @brief Constructor
    explicit EventArea(const size_t, const Event::Type);

    /// @brief Destructor
    ~EventArea() = default;
};

} /// Core namespace

#endif // MONOPOLY_EVENTAREA_HPP
