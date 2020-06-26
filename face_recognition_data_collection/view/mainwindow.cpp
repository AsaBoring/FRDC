#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QFrame(parent)
{
    initSetting();
    initLayout();
}

MainWindow::~MainWindow()
{
    if(v_layout != NULL){v_layout->deleteLater();}
    if(h_detail_layout != NULL){h_detail_layout->deleteLater();}

    if(toolbar != NULL){toolbar->deleteLater();}

    if(detail != NULL){detail->deleteLater();}

    if(menu != NULL){menu->deleteLater();}
    if(video_frame_collect_facedata != NULL){video_frame_collect_facedata->deleteLater();}

}

void MainWindow::initLayout()
{
    /*toolbar*/
    toolbar = new ToolBar(this);

    /*func area*/
    detail = new QFrame(this);
    detail->setFixedSize(MAINWINDOW_WID,MAINWINDOW_HEI-TOOLBAR_HEI);
    detail->setStyleSheet("background:rgba(255,255,255,0);");

    /*menu*/
    menu = new Menu(this);

    /*collect data frame*/
    video_frame_collect_facedata = new CollectFaceData(this);

    h_detail_layout = new QHBoxLayout(this);
    h_detail_layout->setSpacing(0);
    h_detail_layout->setMargin(0);
    h_detail_layout->addSpacing(3);
    h_detail_layout->addWidget(menu);
    h_detail_layout->addStretch();
    h_detail_layout->addWidget(video_frame_collect_facedata);
    h_detail_layout->addSpacing(3);

    detail->setLayout(h_detail_layout);

    v_layout = new QVBoxLayout(this);
    v_layout->setSpacing(0);
    v_layout->setMargin(0);
    v_layout->addWidget(toolbar);
    v_layout->addStretch();
    v_layout->addWidget(detail);

    setLayout(v_layout);
}

void MainWindow::initSetting()
{
    setWindowFlag(Qt::FramelessWindowHint);
    setFixedSize(MAINWINDOW_WID,MAINWINDOW_HEI);
    setStyleSheet(QString("MainWindow{background-color:") + MAINWINDOW_RGB + "}");
}
