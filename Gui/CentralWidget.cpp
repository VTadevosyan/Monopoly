/**
 * MONOPOLY
 */

#include "CentralWidget.hpp"
#include "GameBoard.hpp"
#include "PlayersPane.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QResizeEvent>

#include <iostream>


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
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addStretch();
    mainLayout->addWidget(mPlayersPane);
    mainLayout->addWidget(mGameBoard);
    mainLayout->addStretch();
    mainLayout->setStretchFactor(mPlayersPane, 1);
    mainLayout->setStretchFactor(mGameBoard, 4);
    setLayout(mainLayout);
}

void CentralWidget::resizeEvent(QResizeEvent*)
{
    mPlayersPane->resize(mPlayersPane->width(), mGameBoard->height());
}



} /// Gui namespace
