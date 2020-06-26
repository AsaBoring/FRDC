#include "common.h"

ShadowButton::ShadowButton(QWidget *parent):
    QToolButton(parent)
{

}

void ShadowButton::setShadowRGBA(size_t r, size_t g, size_t b, size_t a)
{
    QString tmp_style = QString("background-color:rgba(") + QString("%1,%2,%3,%4").arg(r).arg(g).arg(b).arg(a) + ")；";
    if(str_style.contains(tmp_style))
    {
        str_style.remove(tmp_style);
    }
    str_style += tmp_style;
    setStyleSheet(str_style);
}

void ShadowButton::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        QPoint offset_point = ev->pos();
        if(abs(offset_point.x() - m_startPoint.x()) > 5 || abs(offset_point.y() - m_startPoint.y()))
        {
            m_isClickble = false;
        }
    }
}

void ShadowButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        m_isClickble = true;
        m_startPoint = ev->pos();
    }
}

void ShadowButton::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        if(m_isClickble)
        {
            if(m_isAllowClick)
            {
                emit sendClicked();
                emit sendClickedWithPtr(this);
                return;
            }
        }
    }
}

void ShadowButton::enterEvent(QEvent *ev)
{

    if(str_style.contains(enter_style))
    {
        str_style.remove(enter_style);
    }
    str_style += enter_style;
    setStyleSheet(str_style);
}

void ShadowButton::leaveEvent(QEvent *ev)
{
    if(str_style.contains(leave_style))
    {
        str_style.remove(leave_style);
    }
    str_style += leave_style;
    setStyleSheet(str_style);
}
