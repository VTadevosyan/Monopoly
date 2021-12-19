/**
 * MONOPOLY
 */

#include "ColorGroup.hpp"

#include "Monopoly/Monopoly.hpp"

#include <cassert>


namespace Core {

ColorGroup::ColorGroup()
{
    initialize();
}

QColor ColorGroup::getColor(size_t index) const
{
    assert(index < BOARD_ITEMS_COUNT);
    auto it = mColorGroupData.find(index);
    if (it == mColorGroupData.end()) {
        return Qt::transparent;
    }
    /// TODO ASSERT
    /// assert(it != mColorGroupData.end());
    return it->second;
}

void ColorGroup::initialize()
{
    mColorGroupData[5] = QColor(230, 11, 51);
    mColorGroupData[15] = QColor(230, 11, 51);
    mColorGroupData[25] = QColor(230, 11, 51);
    mColorGroupData[35] = QColor(230, 11, 51);

    mColorGroupData[12] = QColor(255, 198, 140);
    mColorGroupData[28] = QColor(255, 198, 140);

    mColorGroupData[1] = QColor(240, 156, 208);
    mColorGroupData[3] = QColor(240, 156, 208);

    mColorGroupData[6] = QColor(252, 222, 25);
    mColorGroupData[8] = QColor(252, 222, 25);
    mColorGroupData[9] = QColor(252, 222, 25);

    mColorGroupData[11] = QColor(0, 201, 151);
    mColorGroupData[13] = QColor(0, 201, 151);
    mColorGroupData[14] = QColor(0, 201, 151);

    mColorGroupData[16] = QColor(52, 28, 232);
    mColorGroupData[18] = QColor(52, 28, 232);
    mColorGroupData[19] = QColor(52, 28, 232);

    mColorGroupData[21] = QColor(89, 255, 142);
    mColorGroupData[23] = QColor(89, 255, 142);
    mColorGroupData[24] = QColor(89, 255, 142);

    mColorGroupData[26] = QColor(125, 214, 255);
    mColorGroupData[27] = QColor(125, 214, 255);
    mColorGroupData[29] = QColor(125, 214, 255);

    mColorGroupData[31] = QColor(130, 5, 28);
    mColorGroupData[33] = QColor(130, 5, 28);
    mColorGroupData[34] = QColor(130, 5, 28);

    mColorGroupData[39] = QColor(207, 2, 222);
    mColorGroupData[37] = QColor(207, 2, 222);

}

} /// Core namespace
