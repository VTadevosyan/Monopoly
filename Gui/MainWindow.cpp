/**
 * MONOPOLY
 */

#include "CentralWidget.hpp"
#include "MainWindow.hpp"


namespace Gui {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    CentralWidget* cw = new CentralWidget(this);
    setCentralWidget(cw);
    setWindowIcon(QIcon("Icons/Monopoly.ico"));

    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::gray);
    setAutoFillBackground(true);
    setPalette(p);
}

} /// Gui namespace
