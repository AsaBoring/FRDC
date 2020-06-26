#include "collectfacedata.h"

CollectFaceData::CollectFaceData(QWidget *parent):
    QFrame(parent)
{
    initSetting();
    initLayout();
}

CollectFaceData::~CollectFaceData()
{
    if(video_label != NULL){video_label->deleteLater();}

    if(btn_start_collect != NULL){btn_start_collect->deleteLater();}
    if(btn_start_train != NULL){btn_start_train->deleteLater();}

    if(v_layout != NULL){v_layout->deleteLater();}
    if(h_layout != NULL){h_layout->deleteLater();}

}

void CollectFaceData::importVideo2Frame()
{
}

void CollectFaceData::initLayout()
{
    /*video frame*/
    video_label = new QLabel(this);
    video_label->setAlignment(Qt::AlignCenter);
    video_label->setFixedSize(VIDEO_LABEL_WID,VIDEO_LABEL_HEI);
    video_label->setStyleSheet(QString("background-color:")+BTN_BG_RGB+";color:black;border-radius:5px");
    video_label->setText(tr("waiting for capture device......"));

    /*button*/
    btn_start_collect = new ShadowButton(this);
    btn_start_collect->setFixedSize(BTN_START_COLLECT_WID,BTN_START_COLLECT_HEI);
    btn_start_collect->setStyle(QString("border-radius:5px;background-color:")+BTN_BG_RGB+";color:black;");
    btn_start_collect->setBasicLeaveStyle(QString("background-color:")+BTN_BG_RGB+";color:black;");
    btn_start_collect->setText(tr("start collect"));

    btn_start_train = new ShadowButton(this);
    btn_start_train->setFixedSize(BTN_START_TRAIN_WID,BTN_START_TRAIN_HEI);
    btn_start_train->setStyle(QString("border-radius:5px;background-color:")+BTN_BG_RGB+";color:black;");
    btn_start_train->setBasicLeaveStyle(QString("background-color:")+BTN_BG_RGB+";color:black;");
    btn_start_train->setText(tr("start traing"));

    /*btn layout*/
    h_layout = new QHBoxLayout;
    h_layout->setMargin(0);
    h_layout->setSpacing(0);
    h_layout->addWidget(btn_start_collect);
    h_layout->addWidget(btn_start_train);

    /*gobal layout*/
    v_layout = new QVBoxLayout(this);
    v_layout->setMargin(0);
    v_layout->setSpacing(0);
    v_layout->addSpacing(20);
    v_layout->addWidget(video_label,0,Qt::AlignHCenter);
    v_layout->addStretch();
    v_layout->addLayout(h_layout);
    v_layout->addSpacing(35);
}

void CollectFaceData::initSetting()
{
    setFixedSize(FUNC_AREA_COLLECT_WID,FUNC_AREA_COLLECT_HEI);
    setStyleSheet(QString("CollectFaceData{background-color:") + MAINWINDOW_RGB + ";}");
//    setStyleSheet("background-color:white");
}
