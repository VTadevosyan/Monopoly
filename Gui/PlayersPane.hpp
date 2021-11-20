/**
 * MONOPOLY
 */

#ifndef MONOPOLY_PLAYERSPANE_HPP
#define MONOPOLY_PLAYERSPANE_HPP

#include <QList>
#include <QWidget>


namespace Gui {

class PlayersPaneItem;

/// @class PlayersPane
/// @brief Players Pane
class PlayersPane : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructor
    PlayersPane(QWidget* = nullptr);

    /// @brief Destructor
    ~PlayersPane() = default;

private:
    void initialize();
    void createItems();
    void setupLayout();

private:
    QList<PlayersPaneItem*> mItems;
};

} /// Gui namespace

#endif // MONOPOLY_PLAYERSPANE_HPP
