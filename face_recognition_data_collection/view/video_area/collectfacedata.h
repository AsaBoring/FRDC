#ifndef COLLECTFACEDATA_H
#define COLLECTFACEDATA_H

#include "common.h"

class CollectFaceData : public QFrame
{
    Q_OBJECT
public:
    CollectFaceData(QWidget * parent = nullptr);
    ~CollectFaceData();

    void importVideo2Frame();

    inline ShadowButton * fetchBtnStartCollectPtr(){return btn_start_collect;}
    inline ShadowButton * fetchBtnStartTrainPtr(){return btn_start_train;}

    inline QLabel * fetchVideoLabelPtr(){return video_label;}
private:
    void initLayout();
    void initSetting();

    QLabel * video_label = NULL;
    QFrame * down_frame = NULL;

    ShadowButton * btn_start_collect = NULL;
    ShadowButton * btn_start_train = NULL;

    QVBoxLayout * v_layout = NULL;
    QHBoxLayout * h_layout = NULL;
};

#endif // COLLECTFACEDATA_H
