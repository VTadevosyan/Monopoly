/**
 * MONOPOLY
 */

#include "PlayersPaneItem.hpp"

#include <QLabel>
#include <QVBoxLayout>


namespace Gui {

PlayersPaneItem::PlayersPaneItem(QWidget* parent)
    : QWidget(parent)
{
    static unsigned id = 1;
    QLabel* nameLbl = new QLabel("Player " + QString::fromStdString(std::to_string(id++)));
    nameLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* cashLbl = new QLabel();
    cashLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    cashLbl->setPixmap(QPixmap("Icons/Cash.ico"));
    QVBoxLayout* l = new QVBoxLayout(this);
    l->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    l->addWidget(nameLbl);
    l->addWidget(cashLbl);
    setFont(QFont("Calibri", 32, 100));

    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::darkGray);
    p.setColor(QPalette::Foreground, Qt::white);
    setAutoFillBackground(true);
    setPalette(p);
}

} /// Gui namespace
