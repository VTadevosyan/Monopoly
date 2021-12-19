/**
 * MONOPOLY
 */

#ifndef MONOPOLY_PLAYERSPANEITEM_HPP
#define MONOPOLY_PLAYERSPANEITEM_HPP

#include <QWidget>


class QLabel;

namespace Core {

class Player;

}

namespace Gui {

/// @class PlayersPaneItem
/// @brief Players Pane Item
class PlayersPaneItem : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructor
    /// param[in] Parent widget, player index
    explicit PlayersPaneItem(QWidget*, size_t);

    /// @brief Destructor
    ~PlayersPaneItem() = default;

private:
    void initialize(const Core::Player*);
    void createNameLabel(const Core::Player*);
    void createColorWidget(const Core::Player*);
    void createCashLabel(const Core::Player*);
    void createCashIconLabel();

    void setPalette();
    void setupLayout();

private:
    QWidget* mColorWgt;
    QLabel* mNameLbl;
    QLabel* mCashIconLbl;
    QLabel* mCashLbl;

};

} /// Gui namespace

#endif // MONOPOLY_PLAYERSPANEITEM_HPP
