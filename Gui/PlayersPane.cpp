/**
 * MONOPOLY
 */

#include "Monopoly/Manager.hpp"

#include "PlayersPane.hpp"
#include "PlayersPaneItem.hpp"

#include <QVBoxLayout>


namespace Gui {

PlayersPane::PlayersPane(QWidget* parent)
    : QWidget(parent)
{
    initialize();
}

void PlayersPane::initialize()
{
    createItems();
    setupLayout();
}

void PlayersPane::createItems()
{
    const size_t itemsCount = Monopoly::Manager::get()->playersCount();
    for (size_t i = 0; i < itemsCount; ++i) {
        mItems.append(new PlayersPaneItem(this, i));
    }
}

void PlayersPane::setupLayout()
{
    const unsigned itemsCount = 5; /// TODO
    QVBoxLayout* l = new QVBoxLayout(this);
    for (unsigned i = 0; i < itemsCount; ++i) {
        l->addWidget(mItems[i]);
    }
    l->setContentsMargins(0, 0, 0, 0);
}

} /// Gui namespace
