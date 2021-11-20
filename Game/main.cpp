/**
 * MONOPOLY
 */

#include "Gui/MainWindow.hpp"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gui::MainWindow w;
    w.show();
    return a.exec();
}
