/**
 * MONOPOLY
 */

#include "GameBoard.hpp"
#include "GameBoardItems.hpp"
#include "IconManager.hpp"

#include <QGridLayout>
#include <QResizeEvent>

#include <iostream>


namespace Gui {

GameBoard::GameBoard(QWidget* parent)
    : QWidget(parent)
{
    initialize();
}

void GameBoard::initialize()
{
    initItemTypeMap();
    createItems();
    setupLayout();
    setPalette();
    setMinimumSize(QSize(700, 700));
}

void GameBoard::initItemTypeMap()
{
    /// Corner items
    mItemTypeMap[0] = GameBoardItem::ItemType::Corner;
    mItemTypeMap[10] = GameBoardItem::ItemType::Corner;
    mItemTypeMap[20] = GameBoardItem::ItemType::Corner;
    mItemTypeMap[30] = GameBoardItem::ItemType::Corner;
    /// Horizontal items
    for (size_t i = 1; i < 10; ++i) {
        mItemTypeMap[i] = GameBoardItem::ItemType::Horizontal;
        mItemTypeMap[i + 20] = GameBoardItem::ItemType::Horizontal;
    }
    /// Vertical items
    for (size_t i = 11; i < 20; ++i) {
        mItemTypeMap[i] = GameBoardItem::ItemType::Vertical;
        mItemTypeMap[i + 20] = GameBoardItem::ItemType::Vertical;
    }
}

void GameBoard::createItems()
{
    for (size_t i = 0; i <= BOARD_ITEMS_COUNT; ++i) {
        GameBoardItem* item = nullptr;
        try {
            switch (mItemTypeMap.at(i)) {
                case GameBoardItem::ItemType::Corner: {
                    item = new CornerBoardItem(this, i);
                    break;
                }
                case GameBoardItem::ItemType::Horizontal: {
                    item = new HorizontalBoardItem(this, i);
                    break;
                }
                case GameBoardItem::ItemType::Vertical: {
                    item = new VerticalBoardItem(this, i);
                    break;
                }
                default:;
            }
        } catch(const std::out_of_range&) {
        } catch(...) {
        }
        if (item != nullptr) {
            mItems.push_back(item);
        }
    }
}


void GameBoard::setupLayout()
{
    QGridLayout* l = new QGridLayout(this);
    l->setSpacing(3);

    int col = 2;
    int row = 2;
    for (size_t i = 1; i < 10; ++i) {
        l->addWidget(mItems[i], 0, col++, 2, 1);
    }
    for (size_t i = 11; i < 20; ++i) {
        l->addWidget(mItems[i], row++, 11, 1, 2);
    }
    col = 2;
    for (size_t i = 29; i >= 21; --i) {
        l->addWidget(mItems[i], 12, col++, 2, 1);
    }
    row = 2;
    for (size_t i = 39; i >= 31; --i) {
        l->addWidget(mItems[i], row++, 0, 1, 2);
    }

    l->addWidget(mItems[0], 0, 0, 2, 2);
    l->addWidget(mItems[10], 0, 11, 2, 2);
    l->addWidget(mItems[20], 12, 11, 2, 2);
    l->addWidget(mItems[30], 12, 0, 2, 2);
}

void GameBoard::setPalette()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::darkGray);
    p.setColor(QPalette::Foreground, Qt::white);
    setAutoFillBackground(true);
    QWidget::setPalette(p);
}


void GameBoard::resizeEvent(QResizeEvent* event)
{
    Q_ASSERT(event != nullptr);
    const QSize& newSize = event->size();
    const int w = newSize.width();
    const int h = newSize.height();
    resize(w > h ? QSize(h, h) : QSize(w, w));
}

} /// Gui namespace
