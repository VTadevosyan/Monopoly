/**
 * MONOPOLY
 */

#include "Core/Player.hpp"
#include "Monopoly/Manager.hpp"

#include "PlayersPaneItem.hpp"

#include <QLabel>
#include <QVBoxLayout>


namespace Gui {

/// TODO
QColor getQtColor(color_t c)
{
    switch (c) {
        case color_t::red:
            return QColor(255, 204, 153);
        case color_t::blue:
            return QColor(153, 204, 255);
        case color_t::green:
            return QColor(153, 255, 153);
        case color_t::yellow:
            return QColor(255, 255, 153);
        case color_t::magenta:
            return QColor(229, 204, 255);
    }
    return Qt::white;
}

PlayersPaneItem::PlayersPaneItem(QWidget* parent, size_t playerIndex)
    : QWidget(parent)
{
    Monopoly::Manager* m = Monopoly::Manager::get();
    Core::Player* p = m->findPlayer(playerIndex);
    /// TODO throw
    Q_ASSERT(p != nullptr);
    initialize(p);
}

void PlayersPaneItem::initialize(const Core::Player* p)
{
    Q_ASSERT(p != nullptr);
    createNameLabel(p);
    createColorWidget(p);
    createCashLabel(p);
    createCashIconLabel();
    setupLayout();
    setPalette();
    setFont(QFont(/*"Calibri"*/"Courier", 50, 100));
}

void PlayersPaneItem::createNameLabel(const Core::Player* p)
{
    mNameLbl = new QLabel(p->getName().c_str());
    mNameLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

void PlayersPaneItem::createColorWidget(const Core::Player* p)
{
    mColorWgt = new QWidget(this);
    QPalette cp = mColorWgt->palette();
    cp.setColor(QPalette::Background, getQtColor(p->getColor()));
    mColorWgt->setAutoFillBackground(true);
    mColorWgt->setPalette(cp);
    mColorWgt->setFixedWidth(10);
}

void PlayersPaneItem::createCashLabel(const Core::Player* p)
{
    mCashLbl = new QLabel(this);
    mCashLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    mCashLbl->setText(std::to_string(p->getCash()).c_str());
    mCashLbl->setFont(QFont("Courier", 28, 100));
}

void PlayersPaneItem::createCashIconLabel()
{
    mCashIconLbl = new QLabel(this);
    mCashIconLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    mCashIconLbl->setPixmap(QPixmap("Icons/CashLabelIco.ico"));
}

void PlayersPaneItem::setupLayout()
{
    QHBoxLayout* cashLayout = new QHBoxLayout;
    cashLayout->addWidget(mCashIconLbl);
    cashLayout->addWidget(mCashLbl);
    QVBoxLayout* l = new QVBoxLayout;
    l->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    l->addWidget(mNameLbl);
    l->addLayout(cashLayout);
    QHBoxLayout* ll = new QHBoxLayout(this);
    ll->addWidget(mColorWgt);
    ll->addLayout(l);
    ll->setStretchFactor(mColorWgt, 1);
    ll->setContentsMargins(3, 3, 3, 3);
}

void PlayersPaneItem::setPalette()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::darkGray);
    p.setColor(QPalette::Foreground, Qt::white);
    setAutoFillBackground(true);
    QWidget::setPalette(p);
}

} /// Gui namespace
