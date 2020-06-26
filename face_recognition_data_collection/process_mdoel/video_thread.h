#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include "common.h"

class VideoThread : public QThread
{
    Q_OBJECT
public:
    VideoThread(QLabel * parent);
    ~VideoThread();

    void slotStart();

private:
    QLabel * video_label_handle = NULL;

protected:
    void run() override;

signals:
    void sendErrorInfo(FRDC_CODE error_code);
};

#endif // VIDEOTHREAD_H
