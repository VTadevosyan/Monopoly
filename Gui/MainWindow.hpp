/**
 * MONOPOLY
 */

#ifndef MONOPOLY_MAINWINDOW_HPP
#define MONOPOLY_MAINWINDOW_HPP

#include <QMainWindow>


namespace Gui {

/// @class MainWindow
/// @brief Main Window
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// @brief Constructor
    MainWindow(QWidget* = nullptr);

    /// @brief Destructor
    ~MainWindow() = default;

private:

};

} /// Gui namespace

#endif // MONOPOLY_MAINWINDOW_HPP
