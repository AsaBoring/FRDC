QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp\
    common.cpp

HEADERS += \
    common.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#INCLUDEPATH += C:\Users\houxia2x\Desktop\Asa\opencv\asa_build\install\include\opencv2\
#               C:\Users\houxia2x\Desktop\Asa\opencv\asa_build\install\include
#LIBS += -LC:\Users\houxia2x\Desktop\Asa\opencv\asa_build\install\x64\mingw\bin\
#        -llibopencv_world430

#INCLUDEPATH += $$PWD/../lib/opencv/include/opencv2\
#               $$PWD/../lib/opencv/include/
#LIBS += -L$$PWD/../lib/opencv/\
#        -llibopencv_world430


INCLUDEPATH += C:\Users\houxia2x\Desktop\Asa\opencv\libcontrib\include\opencv2\
               C:\Users\houxia2x\Desktop\Asa\opencv\lib\contrib\include

LIBS += -LC:\Users\houxia2x\Desktop\Asa\opencv\lib\contrib\
        -llibopencv_world430

INCLUDEPATH += $$PWD/process_mdoel
include(process_mdoel/process_mdoel.pri)

INCLUDEPATH += $$PWD/view
include(view/view.pri)

RC_ICONS = resource/icon/icon.ico

RESOURCES += \
    resource.qrc
