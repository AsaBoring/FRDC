#ifndef COMMON_H
#define COMMON_H

#include <QDir>
#include <QFrame>
#include <QLabel>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QLayout>
#include <QString>
#include <QThread>
#include <QMessageBox>
#include <QMainWindow>
#include <QMouseEvent>
#include <QToolButton>

#include <opencv2/face.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

/*mainwindow*/
#define MAINWINDOW_WID 800
#define MAINWINDOW_HEI 500
#define MAINWINDOW_RGB "rgb(79,79,79)"

/*toolbar*/
#define TOOLBAR_WID 800
#define TOOLBAR_HEI 30
#define TOOLBAR_BTN_MIN_WID 30
#define TOOLBAR_BTN_MIN_HEI 20
#define TOOLBAR_BTN_CLOSE_WID 30
#define TOOLBAR_BTN_CLOSE_HEI 20
#define BTN_BG_RGB "rgb(255,228,181)"

/*func area*/
#define FUNC_AREA_MENU_WID 150
#define FUNC_AREA_MENU_HEI 470
#define FUNC_AREA_COLLECT_WID 650
#define FUNC_AREA_COLLECT_HEI 470

#define BTN_FACE_RECG_WID FUNC_AREA_MENU_WID
#define BTN_FACE_RECG_HEI FUNC_AREA_MENU_HEI/2-5
#define BTN_COLLECT_RECG_DATA_WID FUNC_AREA_MENU_WID
#define BTN_COLLECT_RECG_DATA_HEI FUNC_AREA_MENU_HEI/2-5
#define BTN_FUNC_BG_RGB "rgb(255,228,181)"
#define BTN_FUNC_BG_ENTER_RGB "rgb(255,255,255)"

#define VIDEO_LABEL_WID 600
#define VIDEO_LABEL_HEI 350
#define BTN_START_COLLECT_WID 150
#define BTN_START_COLLECT_HEI 45
#define BTN_START_TRAIN_WID 150
#define BTN_START_TRAIN_HEI 45

using namespace cv;
using namespace std;
using namespace face;

enum FRDC_CODE{
  FRDC_ERROR_VIDEO_OPEN_FAILD,
};

class ShadowButton : public QToolButton
{
    Q_OBJECT
public:
    ShadowButton(QWidget * parent = nullptr);

    void setShadowRGBA(size_t r,size_t g,size_t b,size_t a);

    inline void setIsAllowClick(bool para){m_isAllowClick = para;}
    inline void setIsAllowShadow(bool para){m_isAllowShadow = para;}
    inline void setBasicEnterStyle(QString para_str){enter_style = para_str;}
    inline void setBasicLeaveStyle(QString para_str){leave_style = para_str;}
    inline void setStyle(QString para_str){str_style = para_str;setStyleSheet(str_style);}

private:
    bool m_isClickble = true;
    bool m_isSelected = false;
    bool m_isAllowClick = true;
    bool m_isAllowShadow = true;

    QString str_style = "";
    QString enter_style = "background-color:black;color:white;";
    QString leave_style = "background-color:white;color:black;";

    QPoint m_startPoint;
protected:
    void mouseMoveEvent(QMouseEvent * ev);
    void mousePressEvent(QMouseEvent * ev);
    void mouseReleaseEvent(QMouseEvent * ev);

    void enterEvent(QEvent * ev);
    void leaveEvent(QEvent * ev);

signals:
    void sendClicked();
    void sendClickedWithPtr(ShadowButton * ptr);

};

#endif // COMMON_H
