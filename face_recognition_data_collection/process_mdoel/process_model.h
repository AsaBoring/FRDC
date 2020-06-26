#ifndef PROCESS_MODEL_H
#define PROCESS_MODEL_H

#include "mainwindow.h"
#include "video_thread.h"

class ProcessModel : public QObject
{
    Q_OBJECT
public:
    ProcessModel(MainWindow * obj);
    ~ProcessModel();

    void slotCloseWindow();
    void slotMinsizeWindow();
    void slotMoveMainWindow(QPoint paraPoint);
    void slotBtnStartCollectDataClicked();

private:
    MainWindow * process_handle = NULL;
    VideoThread * collect_video_thread = NULL;

    void initConnect();
};

#endif // PROCESS_MODEL_H
