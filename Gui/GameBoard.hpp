/**
 * MONOPOLY
 */

#ifndef MONOPOLY_GAMEBOARD_HPP
#define MONOPOLY_GAMEBOARD_HPP

#include "GameBoardItems.hpp"

#include <QWidget>

#include <vector>
#include <map>


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

public:
    /// @brief Handles resize event
    void resizeEvent(QResizeEvent*) override;

public:


private:
    void initialize();
    void initItemTypeMap();

    void createItems();
    /*void createTopHorizontalItems();
    void createBottomHorizontalItems();
    void createTopVerticalItems();
    void createBottomVerticalItems();
    void createCornerItems();*/

    void setupLayout();
    void setPalette();

private:
    std::vector<GameBoardItem*> mItems;
    std::map<int, GameBoardItem::ItemType> mItemTypeMap;
};

} /// Gui namespace

#endif // MONOPOLY_GAMEBOARD_HPP
