/**
 * MONOPOLY
 */

#ifndef MONOPOLY_COLORGROUP_H
#define MONOPOLY_COLORGROUP_H

#include <QColor>

#include <map>


namespace Core {

/// @class ColorGroup
class ColorGroup
{
public:
    /// @brief Constructor
    ColorGroup();

    /// @brief Destructor
    ~ColorGroup() = default;

public:
    /// @brief Gets the color from specified index
    QColor getColor(size_t) const;

private:
    void initialize();

private:
    std::map<int, QColor> mColorGroupData;
};

} /// Core namespace

#endif // MONOPOLY_COLORGROUP_H
