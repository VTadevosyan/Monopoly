QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game/Manager.cpp \
    Game/main.cpp \
    Gui/CentralWidget.cpp \
    Gui/GameBoard.cpp \
    Gui/MainWindow.cpp \
    Gui/PlayersPane.cpp \
    Gui/PlayersPaneItem.cpp

HEADERS += \
    Game/Manager.hpp \
    Gui/CentralWidget.hpp \
    Gui/GameBoard.hpp \
    Gui/MainWindow.hpp \
    Gui/PlayersPane.hpp \
    Gui/PlayersPaneItem.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Gui/Icons/Monopoly.ico
