#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menu.h"
#include "toolbar.h"
#include "recgface.h"
#include "collectfacedata.h"

#include "common.h"

class MainWindow : public QFrame
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    inline Menu * fetchMenuPtr(){return menu;}
    inline ToolBar * fetchToolbarPtr(){return toolbar;}
    inline CollectFaceData * fetchCollectDataPtr(){return video_frame_collect_facedata;}

private:
    void initLayout();
    void initSetting();

    QVBoxLayout * v_layout = NULL;

    ToolBar * toolbar = NULL;

    QFrame * detail = NULL;
    QHBoxLayout * h_detail_layout = NULL;

    /*func area*/
    Menu * menu = NULL;
    CollectFaceData * video_frame_collect_facedata = NULL;

};
#endif // MAINWINDOW_H
