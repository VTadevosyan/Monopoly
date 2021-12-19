/**
 * MONOPOLY
 */

#include "GameBoardItems.hpp"
#include "IconManager.hpp"

#include "Core/Engine.hpp"
#include "Core/ColorGroup.hpp"
#include "Core/Manager.hpp"

#include <QLabel>
#include <QMatrix>
#include <QPainter>
#include <QVBoxLayout>

#include <iostream>


namespace Gui {

/* GameBoardItem */

GameBoardItem::GameBoardItem(QWidget* parent, size_t index)
    : QWidget(parent)
    , mIndex(index)
{
    Q_ASSERT(isValidIndex());

    //setScaledContents(true);
    //setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    initialize();
}

void GameBoardItem::initialize()
{
    createFields();
    setPalette();
    setContentsMargins(0, 0, 0, 0);
}

size_t GameBoardItem::getIndex() const noexcept
{
    return mIndex;
}

void GameBoardItem::setPalette()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    QWidget::setPalette(p);
}

void GameBoardItem::createFields()
{
    mIcon = new QLabel(this);
}

void GameBoardItem::setIcon()
{

}

bool GameBoardItem::isValidIndex() const noexcept
{
    return mIndex >= 0 && mIndex <= BOARD_ITEMS_COUNT;
}

/* HorizontalBoardItem */
HorizontalBoardItem::HorizontalBoardItem(QWidget* parent, size_t index)
    : GameBoardItem(parent, index)
    , mOnTop(index < BOARD_ITEMS_COUNT / 2)
{
    /// XXX
    mIcon->setScaledContents(true);
    mIcon->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    mIcon->setPixmap(QPixmap(IconManager::get()->getIcon(mIndex)));

    /// XXX
    mPrice = new PriceLabel(this, GameBoardItem::ItemType::Horizontal);
    //mPrice->setContentsMargins(0, 0, 0, 0);
    mBranch = new QLabel(this);

    setupLayout();
    setMinimumSize(50, 100);
}

void HorizontalBoardItem::setupLayout()
{
    QVBoxLayout* l = new QVBoxLayout(this);
    if (mOnTop) {
        l->addWidget(mPrice);
    } else {
        l->addWidget(mBranch);
    }
    l->addWidget(mIcon);
    if (mOnTop) {
        l->addWidget(mBranch);
    } else {
        l->addWidget(mPrice);
    }
    l->setStretchFactor(mPrice, 1);
    l->setStretchFactor(mIcon, 8);
    l->setStretchFactor(mBranch, 1);
    l->setContentsMargins(5, 5, 5, 5);
}

/* VerticalBoardItem */
VerticalBoardItem::VerticalBoardItem(QWidget* parent, size_t index)
    : GameBoardItem(parent, index)
    , mOnLeft(index > BOARD_ITEMS_COUNT / 2)
{
    /// XXX
    mIcon->setScaledContents(true);
    mIcon->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    mIcon->setPixmap(QPixmap(IconManager::get()->getIcon(mIndex)));

    mPrice = new PriceLabel(this, GameBoardItem::ItemType::Vertical);
    //mPrice->setContentsMargins(0, 0, 0, 0);
    mBranch = new QLabel(this);


    setupLayout();
    setMinimumSize(100, 50);
}

void VerticalBoardItem::setupLayout()
{
    QHBoxLayout* l = new QHBoxLayout(this);
    if (mOnLeft) {
        l->addWidget(mPrice);
    } else {
        l->addWidget(mBranch);
    }
    l->addWidget(mIcon);
    if (mOnLeft) {
        l->addWidget(mBranch);
    } else {
        l->addWidget(mPrice);
    }
    l->setStretchFactor(mPrice, 1);
    l->setStretchFactor(mIcon, 8);
    l->setStretchFactor(mBranch, 1);
    l->setContentsMargins(5, 5, 5, 5);
}


/* CornerBoardItem */
CornerBoardItem::CornerBoardItem(QWidget* parent, size_t index)
    : GameBoardItem(parent, index)
{
    /// XXX
    mIcon->setScaledContents(true);
    mIcon->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    mIcon->setPixmap(QPixmap(IconManager::get()->getIcon(mIndex)));

    setupLayout();
    setMinimumSize(100, 100);
}

void CornerBoardItem::setupLayout()
{
    QVBoxLayout* l = new QVBoxLayout(this);
    l->addWidget(mIcon);
}

PriceLabel::PriceLabel(QWidget* parent, GameBoardItem::ItemType t)
    : QLabel(parent)
    , mType(t)
{
    const Core::Engine* e = Core::Manager::get()->getEngine();
    const QColor& c = e->getColorGroup()->getColor(static_cast<GameBoardItem*>(parent)->getIndex());

    QPalette p(palette());
    p.setColor(QPalette::Foreground, Qt::white);
    p.setColor(QPalette::Background, c);
    setAutoFillBackground(true);
    setPalette(p);
    //setContentsMargins(-10, -10, -10, -10);

    //setScaledContents(true);
    //setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

}

void PriceLabel::paintEvent(QPaintEvent*)
{
    const Core::Engine* e = Core::Manager::get()->getEngine();
    QPainter painter(this);
    QFont f = painter.font();
    f.setBold(true);
    f.setFamily("Courier");
    f.setPointSize(11);
    painter.setFont(f);
    //painter.setFont(QFont("Courier", 10, 100));
    /*if (mType == GameBoardItem::ItemType::Vertical) {
        painter.rotate(90);
    }*/
    const size_t index = static_cast<GameBoardItem*>(parent())->getIndex();
    const cash_t price = e->getBuildingPrice(index);
    if (price == 0) {
        return;
    }
    const QString& p = QString(std::to_string(price).c_str());

    if (mType == GameBoardItem::ItemType::Vertical) {
        painter.rotate(90);
        QRect r = rect();
        r.setWidth(r.width() + 5);
        std::cout << "V = " << r.x() << " " << r.y() << " " << r.width() << " " << r.height() << std::endl;
        //painter.drawText(rect().center().x(), rect().center().y()/*, Qt::AlignCenter*/, p);
        painter.drawText(0, 0, p);

    } else {
        QRect r = rect();
        std::cout << "H = " << r.x() << " " << r.y() << " " << r.width() << " " << r.height() << std::endl;
        painter.drawText(rect(),Qt::AlignCenter, p);
        //painter.drawText(0, 10, p);
    }

    painter.end();

}

}/// Gui namespace

