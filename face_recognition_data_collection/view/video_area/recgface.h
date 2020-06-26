#ifndef RECGFACE_H
#define RECGFACE_H

#include "common.h"

class RecgFace : public QFrame
{
    Q_OBJECT
public:
    RecgFace(QWidget *parent = nullptr);

private:
    void initLayout();
    void initSetting();
};

#endif // RECGFACE_H
