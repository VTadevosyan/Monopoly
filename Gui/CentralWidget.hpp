/**
 * MONOPOLY
 */

#ifndef MONOPOLY_CENTRALWIDGET_HPP
#define MONOPOLY_CENTRALWIDGET_HPP

#include <QWidget>


namespace Gui {

class PlayersPane;
class GameBoard;

/// @class CentralWidget
/// @brief Represents main widget
class CentralWidget : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructor
    CentralWidget(QWidget* = nullptr);

    /// @brief Destructor
    ~CentralWidget() = default;

private:
    void initialize();
    void createWidgets();
    void setupLayout();

private:
    PlayersPane* mPlayersPane = nullptr;
    GameBoard* mGameBoard = nullptr;
};


} /// Gui namespace

#endif // MONOPOLY_CENTRALWIDGET_HPP
