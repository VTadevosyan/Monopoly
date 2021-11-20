/**
 * MONOPOLY
 */

#ifndef MONOPOLY_PLAYERSPANEITEM_HPP
#define MONOPOLY_PLAYERSPANEITEM_HPP

#include <QWidget>


namespace Gui {

/// @class PlayersPaneItem
/// @brief Players Pane Item
class PlayersPaneItem : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructor
    PlayersPaneItem(QWidget* = nullptr);

    /// @brief Destructor
    ~PlayersPaneItem() = default;
};

} /// Gui namespace

#endif // MONOPOLY_PLAYERSPANEITEM_HPP
