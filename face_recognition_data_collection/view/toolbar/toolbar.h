#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "common.h"

class ToolBar : public QFrame
{
    Q_OBJECT
public:
    ToolBar(QWidget * parent = 0);
    ~ToolBar();

    inline ShadowButton * fetchBtnMinPtr(){return btn_min;}
    inline ShadowButton * fetchBtnClosePtr(){return btn_close;}

private:
    void initLayout();
    void initSetting();

    QWidget * getMainWindowPtr(QWidget * parent);

    bool m_move = false;

    QPoint m_startPoint;
    QPoint m_windowPoint;

    QHBoxLayout * h_layout = NULL;

    ShadowButton * btn_min = NULL;
    ShadowButton * btn_close = NULL;

protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent * ev);
    void mouseReleaseEvent(QMouseEvent * ev);

signals:
     void sendMoveMainWindow(QPoint pointMove);
};

#endif // TOOLBAR_H
