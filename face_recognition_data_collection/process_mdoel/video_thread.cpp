#include "video_thread.h"

VideoThread::VideoThread(QLabel *parent):
    QThread(parent)
{
    video_label_handle = parent;
}

VideoThread::~VideoThread()
{

}

void VideoThread::slotStart()
{
    if(isRunning())
    {
        wait();
    }

    start(HighPriority);
}

void VideoThread::run()
{
    qDebug()<<"video thread run";
    if(video_label_handle == NULL)
    {
        /*get video label for show failed*/
        return;
    }

    /*open default capture*/
    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        /*open default capture failed*/
        emit sendErrorInfo(FRDC_ERROR_VIDEO_OPEN_FAILD);
        qDebug()<<"capture open failed";
        return;
    }

    /*加载人像识别模型(haar人脸模型文件放在相对位置中，如改变该文件位置需注意修改haar_path)*/
    CascadeClassifier haar_cascade;
    QString current_path = QDir::currentPath();
    QString haar_path = current_path + "/../face_recognition_data_collection/resource/recg_model_file/haarcascade_frontalface_alt_tree.xml";
    haar_cascade.load(haar_path.toUtf8().constData());
    qDebug()<<"load haar model";

    size_t wid = video_label_handle->width();
    size_t hei = video_label_handle->height();
    qDebug()<<"video_label_handle wid is : "<<wid;
    qDebug()<<"video_label_handle hei is : "<<hei;

    Mat src_image;
    while (cap.read(src_image)) {
        /*旋转成像*/
        flip(src_image,src_image,1);

        /*获取人脸区域并画框显示*/
        Mat gray_image;
        vector<Rect> vec_faces;
        cvtColor(src_image,gray_image,COLOR_BGR2GRAY);
        haar_cascade.detectMultiScale(gray_image,vec_faces);
        if(vec_faces.size() != 0)
        {
            for(size_t var = 0 ; var < vec_faces.size() ; ++var)
            {
                Rect face_tmp = vec_faces[var];
                rectangle(src_image,face_tmp,Scalar(0,0,255),3,8,0);
                qDebug()<<"x is : "<<face_tmp.x;
                qDebug()<<"y is : "<<face_tmp.y;
                qDebug()<<"wid is : "<<face_tmp.width;
                qDebug()<<"hei is : "<<face_tmp.height;
            }
        }else{
            Rect rect_normal(235,160,150,160);
            rectangle(src_image,rect_normal,Scalar(0,0,255),3,8,0);
        }

        /*转化Mat卫QImage*/
        cvtColor(src_image,src_image,COLOR_BGR2RGB);
        QImage video_image((const unsigned char *)src_image.data,\
                           src_image.cols,\
                           src_image.rows,\
                           src_image.step,\
                           QImage::Format_RGB888);
        video_label_handle->setPixmap(QPixmap::fromImage(video_image));
        waitKey(10);
    }
}
