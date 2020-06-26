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

    /*加载人像识别模型*/
    CascadeClassifier haar_cascade;
    haar_cascade.load("C:/Users/houxia2x/Desktop/Asa/opencv/project/FRDC/face_recognition_data_collection/resource/recg_model_file/haarcascade_frontalface_alt_tree.xml");
    qDebug()<<"load haar model";

    size_t wid = video_label_handle->width();
    size_t hei = video_label_handle->height();
    qDebug()<<"video_label_handle wid is : "<<wid;
    qDebug()<<"video_label_handle hei is : "<<hei;


    Mat src_image;
    while (cap.read(src_image)) {
        /*旋转成像*/
        flip(src_image,src_image,1);
        Mat gray_image;
        vector<Rect> vec_faces;
        cvtColor(src_image,gray_image,COLOR_BGR2GRAY);
        haar_cascade.detectMultiScale(gray_image,vec_faces);
        for(size_t var = 0 ; var < vec_faces.size() ; ++var)
        {
            Rect face_tmp = vec_faces[var];
            rectangle(src_image,face_tmp,Scalar(0,0,255),2,8,0);
            resize(src_image,src_image,Size(wid,hei),1.0,1.0,INTER_CUBIC);
        }
        cvtColor(src_image,src_image,COLOR_BGR2RGB);
        QImage video_image((const unsigned char *)src_image.data,\
                           src_image.cols,\
                           src_image.rows,\
                           src_image.step,\
                           QImage::Format_RGB888);
        video_label_handle->setPixmap(QPixmap::fromImage(video_image));
        waitKey(20);
    }
}
