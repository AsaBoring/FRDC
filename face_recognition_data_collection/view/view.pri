SOURCES += \
    $$PWD/mainwindow.cpp

HEADERS += \
    $$PWD/mainwindow.h

INCLUDEPATH += $$PWD/toolbar
include(toolbar/toolbar.pri)

INCLUDEPATH += $$PWD/menu
include(menu/menu.pri)

INCLUDEPATH += $$PWD/video_area
include(video_area/video_area.pri)
