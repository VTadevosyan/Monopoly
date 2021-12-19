/**
 * MONOPOLY
 */

#ifndef MONOPOLY_AREA_HPP
#define MONOPOLY_AREA_HPP

#include <string>


namespace Core {

/// @class Area
/// @brief Area
class Area
{
public:
    enum class Type
    {
        Event,
        Building,
        Jail
    };

public:
    /// @brief Constructor
    Area(const size_t, const Type, const std::string& = "");

    /// @brief Destructor
    virtual ~Area() = default;

public:
    /// @brief Gets the index of current area
    size_t getIndex() const noexcept;

    /// @brief Gets the area type
    Type getType() const noexcept;

    /// @brief Gets the label of area
    std::string getLabel() const noexcept;

private:
    size_t mIndex;
    Type mType;
    std::string mLabel;
};

} /// Core namespace

#endif // MONOPOLY_AREA_HPP
