#include "toolbar.h"

ToolBar::ToolBar(QWidget *parent)
    : QFrame(parent)
{
    initSetting();
    initLayout();
}

ToolBar::~ToolBar()
{
    if(h_layout != NULL){h_layout->deleteLater();}

    if(btn_min != NULL){btn_min->deleteLater();}
    if(btn_close != NULL){btn_close->deleteLater();}
}

void ToolBar::initLayout()
{
    btn_close = new ShadowButton(this);
    btn_close->setFixedSize(TOOLBAR_BTN_CLOSE_WID,TOOLBAR_BTN_CLOSE_HEI);
    btn_close->setStyle(QString("border-radius:5px;background-color:")+BTN_BG_RGB+";color:black;");
    btn_close->setBasicLeaveStyle(QString("background-color:")+BTN_BG_RGB+";color:black;");
    btn_close->setText(tr("close"));

    btn_min = new ShadowButton(this);
    btn_min->setFixedSize(TOOLBAR_BTN_MIN_WID,TOOLBAR_BTN_MIN_HEI);
    btn_min->setStyle(QString("border-radius:5px;background-color:")+BTN_BG_RGB+";color:black;");
    btn_min->setBasicLeaveStyle(QString("background-color:")+BTN_BG_RGB+";color:black;");
    btn_min->setText(tr("min"));

    h_layout = new QHBoxLayout(this);
    h_layout->setSpacing(0);
    h_layout->setMargin(0);
    h_layout->addStretch();
    h_layout->addWidget(btn_min);
    h_layout->addSpacing(10);
    h_layout->addWidget(btn_close);
    h_layout->addSpacing(20);

    setLayout(h_layout);
}

void ToolBar::initSetting()
{
    setFixedSize(TOOLBAR_WID,TOOLBAR_HEI);
    setStyleSheet("background-color:white");
}

QWidget *ToolBar::getMainWindowPtr(QWidget *parent)
{
    parent = parent->parentWidget();

    if(parent->inherits("MainWindow"))
    {
        return parent;
    }else{
        return getMainWindowPtr(parent);
    }
}

void ToolBar::mouseMoveEvent(QMouseEvent *ev)
{
    if (ev->buttons() & Qt::LeftButton)
     {
         QPoint relativePos = ev->globalPos() - m_startPoint;
         emit sendMoveMainWindow(m_windowPoint + relativePos);
    }
}

void ToolBar::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
     {
         m_move = true;
         m_startPoint = ev->globalPos();
         m_windowPoint = getMainWindowPtr(this)->frameGeometry().topLeft();
     }
}

void ToolBar::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        m_move = false;
    }
}
