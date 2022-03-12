/*
 *
 SLStudio - Platform for Real-Time  Structured Light
 (c) Jakob Wilm, jw@vision-consulting.dk
 *
*/

#ifndef SLVIDEOWIDGET_H
#define SLVIDEOWIDGET_H

#include <QLabel>
#include <QResizeEvent>

#include "Camera.h"
#include <opencv2/opencv.hpp>

class SLVideoWidget : public QLabel {
    Q_OBJECT
    public:
        explicit SLVideoWidget(QWidget *parent = 0) : QLabel(parent){}
    signals:

    public slots:
        void showFrame(CameraFrame frame);
        void showFrameCV(cv::Mat frame);
        void resizeEvent(QResizeEvent *event);
    protected:

    private:
        QPixmap pixmap;
};

#endif
