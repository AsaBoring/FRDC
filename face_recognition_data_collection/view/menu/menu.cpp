#include "menu.h"

Menu::Menu(QWidget *parent):
    QFrame(parent)
{
    initSetting();
    initLayout();
}

Menu::~Menu()
{
    if(v_layout != NULL){v_layout->deleteLater();}

    if(btn_test_face_recg != NULL){btn_test_face_recg->deleteLater();}
    if(btn_collect_recg_data != NULL){btn_collect_recg_data->deleteLater();}
}

void Menu::initLayout()
{
    /*func area menu*/
    btn_collect_recg_data = new ShadowButton(this);
    btn_collect_recg_data->setFixedSize(BTN_COLLECT_RECG_DATA_WID,BTN_COLLECT_RECG_DATA_HEI);
    btn_collect_recg_data->setStyle(QString("border-radius:15px;border:3px solid white;background-color:")+BTN_FUNC_BG_RGB+";color:black;");
    btn_collect_recg_data->setBasicLeaveStyle(QString("background-color:")+BTN_FUNC_BG_RGB+";color:black;");
    btn_collect_recg_data->setText(tr("collect recg data"));

    btn_test_face_recg = new ShadowButton(this);
    btn_test_face_recg->setFixedSize(BTN_FACE_RECG_WID,BTN_FACE_RECG_HEI);
    btn_test_face_recg->setStyle(QString("border-radius:15px;border:3px solid white;background-color:")+BTN_FUNC_BG_RGB+";color:black;");
    btn_test_face_recg->setBasicLeaveStyle(QString("background-color:")+BTN_FUNC_BG_RGB+";color:black;");
    btn_test_face_recg->setText(tr("face recg"));

    v_layout = new QVBoxLayout(this);
    v_layout->setSpacing(0);
    v_layout->setMargin(0);
    v_layout->addStretch();
    v_layout->addWidget(btn_collect_recg_data);
    v_layout->addSpacing(4);
    v_layout->addWidget(btn_test_face_recg);
    v_layout->addStretch();

    setLayout(v_layout);
}

void Menu::initSetting()
{
    setFixedSize(FUNC_AREA_MENU_WID,FUNC_AREA_MENU_HEI);
    setStyleSheet(QString("background-color:") + MAINWINDOW_RGB);
}
