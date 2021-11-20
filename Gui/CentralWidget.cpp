/**
 * MONOPOLY
 */

#include "CentralWidget.hpp"
#include "GameBoard.hpp"
#include "PlayersPane.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>


namespace Gui {

CentralWidget::CentralWidget(QWidget* parent)
    : QWidget(parent)
{
    initialize();
}

void CentralWidget::initialize()
{
    createWidgets();
    setupLayout();
}

void CentralWidget::createWidgets()
{
    mPlayersPane = new PlayersPane(this);
    mGameBoard = new GameBoard(this);
}

void CentralWidget::setupLayout()
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(mPlayersPane);
    mainLayout->addWidget(mGameBoard);
    mainLayout->setStretchFactor(mPlayersPane, 1);
    mainLayout->setStretchFactor(mGameBoard, 3);
    setLayout(mainLayout);
}


} /// Gui namespace
