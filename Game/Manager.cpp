/**
 * MONOPOLY
 */

#include "Manager.hpp"

namespace Monopoly {

Manager* Manager::get()
{
    static Manager m;
    return &m;
}

Manager::Manager()
{
}

} /// Monopoly namespace
