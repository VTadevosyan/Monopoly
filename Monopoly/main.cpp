/**
 * MONOPOLY
 */

#include "Gui/MainWindow.hpp"
#include "Monopoly/Manager.hpp"

#include <QApplication>


int main(int argc, char *argv[])
{
    try {
        QApplication a(argc, argv);

        Monopoly::Manager* m = Monopoly::Manager::get();
        Q_ASSERT(m != nullptr);
        m->registerPlayer("Annie");
        m->registerPlayer("John");
        m->registerPlayer("Susan");
        m->registerPlayer("Marie");
        m->registerPlayer("Peter");

        if (!m->canLaunchGame()) {
            return 0;
        }

        Gui::MainWindow w;
        w.show();
        return a.exec();
    } catch(...)  {
    }
    return 0;
}
