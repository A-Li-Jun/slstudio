/*
 *
 SLStudio - Platform for Real-Time  Structured Light
 (c) Jakob Wilm, jw@vision-consulting.dk
 *
*/

#ifndef SLSTUDIO_H
#define SLSTUDIO_H

#include <QElapsedTimer>
#include <QMainWindow>
#include <QPointer>
#include <QSettings>

#include "SLPointCloudWidget.h"
#include "SLScanWorker.h"
#include "SLTrackerDialog.h"
#include "SLTrackerWorker.h"
#include "SLVideoDialog.h"

namespace Ui {
class SLStudio;
}

class SLStudio : public QMainWindow {
  Q_OBJECT

public:
  explicit SLStudio(QWidget *parent = 0);
  void closeEvent(QCloseEvent *event);
  ~SLStudio();

private slots:
  void onActionStart();
  void onActionStop();
  void onScanWorkerFinished();

  void onActionCalibration();
  void onActionLoadCalibration();
  void onActionPreferences();
  void onActionExportCalibration();

  void updateDisplayRate();
  void receiveNewPointCloud(PointCloudConstPtr pointCloud);

  void imshow(const char *windowName, cv::Mat im, unsigned int x,
              unsigned int y);
  void hist(const char *windowName, cv::Mat im, unsigned int x, unsigned int y);

  void onShowHistogram(cv::Mat im);
  void onShowShading(cv::Mat im);
  void onShowCameraFrames(std::vector<cv::Mat> frameSeq);
  void onShowDecoderUp(cv::Mat im);
  void onShowDecoderVp(cv::Mat im);

  void onActionAbout();

signals:
  void newPointCloud(PointCloudConstPtr pointCloud);

private:
  Ui::SLStudio *ui;
  std::vector<unsigned int> displayIntervals;

  SLScanWorker *scanWorker;
  QThread *scanWorkerThread;

  SLDecoderWorker *decoderWorker;
  QThread *decoderThread;

  SLTriangulatorWorker *triangulatorWorker;
  QThread *triangulatorThread;

  QElapsedTimer *time;
  QSettings *settings;

  SLVideoDialog *histogramDialog, *shadingDialog, *cameraFramesDialog,
      *decoderUpDialog, *decoderVpDialog;
  SLTrackerDialog *trackerDialog;

public:
};

#endif
