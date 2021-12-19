/**
 * MONOPOLY
 */

#ifndef MONOPOLY_GAMEBOARDITEM_HPP
#define MONOPOLY_GAMEBOARDITEM_HPP

#include "Monopoly/Monopoly.hpp"

#include <QLabel>
#include <QPaintEvent>


namespace Gui {

class PriceLabel;

/// @class GameBoardItem
/// @brief Game Board Item
class GameBoardItem : public QWidget
{
    Q_OBJECT

public:
    enum class ItemType {
        Corner = 0,
        Horizontal,
        Vertical
    };

public:
    /// @brief Constructor
    explicit GameBoardItem(QWidget*, size_t);

    /// @brief Destructor
    ~GameBoardItem() = default;


public:
    /// @brief Gets the area index
    size_t getIndex() const noexcept;



private:
    void initialize();
    void createFields();
    void setPalette();
    void setIcon();

    bool isValidIndex() const noexcept;


protected:
    QLabel* mIcon = nullptr;
    size_t mIndex = BOARD_ITEMS_COUNT + 1;
};


/// @class HorizontalBoardItem
class HorizontalBoardItem : public GameBoardItem
{
    Q_OBJECT

public:
    /// @brief Constructor
    explicit HorizontalBoardItem(QWidget*, size_t);

    /// @brief Destructor
    ~HorizontalBoardItem() = default;

private:
    void setupLayout();

private:
    PriceLabel* mPrice = nullptr;
    QLabel* mBranch = nullptr;
    const bool mOnTop;

};


/// @class VerticalBoardItem
class VerticalBoardItem : public GameBoardItem
{
    Q_OBJECT

public:
    /// @brief Constructor
    explicit VerticalBoardItem(QWidget*, size_t);

    /// @brief Destructor
    ~VerticalBoardItem() = default;

private:
    void setupLayout();

private:
    PriceLabel* mPrice = nullptr;
    QLabel* mBranch = nullptr;
    const bool mOnLeft;

};


/// @class CornerBoardItem
class CornerBoardItem : public GameBoardItem
{
    Q_OBJECT

public:
    /// @brief Constructor
    explicit CornerBoardItem(QWidget*, size_t);

    /// @brief Destructor
    ~CornerBoardItem() = default;

private:
    void setupLayout();

};


/// @class PriceLabel
class PriceLabel : public QLabel
{
    Q_OBJECT

public:
    PriceLabel(QWidget*, GameBoardItem::ItemType);

    void paintEvent(QPaintEvent*) override;

private:
    GameBoardItem::ItemType mType;
};

} /// Gui namespace

#endif // GAMEBOARDITEM_HPP
