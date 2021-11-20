/**
 * MONOPOLY
 */

#ifndef MONOPOLY_GAMEBOARD_HPP
#define MONOPOLY_GAMEBOARD_HPP

#include <QWidget>


namespace Gui {

/// @class GameBoard
/// @brief Game Board
class GameBoard : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructor
    GameBoard(QWidget* = nullptr);

    /// @brief Destructor
    ~GameBoard() = default;
};

} /// Gui namespace

#endif // MONOPOLY_GAMEBOARD_HPP
