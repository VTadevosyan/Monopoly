/**
 * MONOPOLY
 */

#include "Area.hpp"


namespace Core {

Area::Area(const size_t index, const Type type, const std::string& lbl)
    : mIndex(index)
    , mType(type)
    , mLabel(lbl)
{

}

std::string Area::getLabel() const noexcept
{
    return mLabel;
}

Area::Type Area::getType() const noexcept
{
    return mType;
}

size_t Area::getIndex() const noexcept
{
    return mIndex;
}

} /// Core namespace
