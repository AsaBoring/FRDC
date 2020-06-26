#ifndef Menu_H
#define Menu_H

#include "common.h"

class Menu : public QFrame
{
public:
    Menu(QWidget * parent);
    ~Menu();

    void initLayout();
    void initSetting();

    inline ShadowButton * fetchBtnTestFaceRecgPtr(){return btn_test_face_recg;}
    inline ShadowButton * fetchBtnCollectRecgDataPtr(){return btn_collect_recg_data;}

private:
    QVBoxLayout * v_layout = NULL;

    ShadowButton * btn_test_face_recg = NULL;
    ShadowButton * btn_collect_recg_data = NULL;
};

#endif // Menu_H
