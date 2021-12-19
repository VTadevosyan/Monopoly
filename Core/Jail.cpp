/**
 * MONOPOLY
 */

#include "Jail.hpp"

#include <QtGlobal>


namespace Core {

Jail::Jail(const size_t index)
    : Area(index, Area::Type::Jail)
{
}

} /// Core namespace
