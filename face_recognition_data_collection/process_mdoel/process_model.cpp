#include "process_model.h"

ProcessModel::ProcessModel(MainWindow *obj)
{
    if(obj != NULL)
    {
        process_handle = obj;
    }else{
        return;
    }

    initConnect();
}

ProcessModel::~ProcessModel()
{
    if(collect_video_thread != NULL){collect_video_thread->exit();collect_video_thread->deleteLater();}
}

void ProcessModel::slotCloseWindow()
{
    QMessageBox * msgBox = new QMessageBox(process_handle);
    if(QMessageBox::Yes == msgBox->question(process_handle,"Close window","Do you wanna close app?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
    {
        msgBox->deleteLater();
        process_handle->close();
    }
}

void ProcessModel::slotMinsizeWindow()
{
    process_handle->showMinimized();
}

void ProcessModel::initConnect()
{
    connect(process_handle->fetchToolbarPtr(),&ToolBar::sendMoveMainWindow,this,&ProcessModel::slotMoveMainWindow);
    connect(process_handle->fetchToolbarPtr()->fetchBtnMinPtr(),&ShadowButton::sendClicked,this,&ProcessModel::slotMinsizeWindow);
    connect(process_handle->fetchToolbarPtr()->fetchBtnClosePtr(),&ShadowButton::sendClicked,this,&ProcessModel::slotCloseWindow);

    connect(process_handle->fetchCollectDataPtr()->fetchBtnStartCollectPtr(),&ShadowButton::sendClicked,this,&ProcessModel::slotBtnStartCollectDataClicked);
}

void ProcessModel::slotMoveMainWindow(QPoint paraPoint)
{
    process_handle->move(paraPoint);
}

void ProcessModel::slotBtnStartCollectDataClicked()
{
    qDebug()<<"slotBtnStartCollectDataClicked";
    if(collect_video_thread != NULL)
    {
        collect_video_thread->start();
    }else{
        collect_video_thread = new VideoThread(process_handle->fetchCollectDataPtr()->fetchVideoLabelPtr());
        collect_video_thread->start();
    }
}
