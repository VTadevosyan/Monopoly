/**
 * MONOPOLY
 */

#include "GameBoard.hpp"


namespace Gui {

GameBoard::GameBoard(QWidget* parent)
    : QWidget(parent)
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::darkGray);
    p.setColor(QPalette::Foreground, Qt::white);
    setAutoFillBackground(true);
    setPalette(p);
}

} /// Gui namespace
