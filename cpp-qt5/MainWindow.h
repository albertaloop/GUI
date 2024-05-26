#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "PodNetWidget.h"
#include "CircularBuffer.h"

class MainWindow : public QMainWindow
{
private:
  QVBoxLayout * topVLayout;
  QHBoxLayout * podNetHLayout;
  QHBoxLayout * btnHLayout;
  QHBoxLayout * motorBtnHLayout;
  QHBoxLayout * brakeBtnHLayout;
  QVBoxLayout * brakeMotorBtnVLayout;
  QVBoxLayout * ledBtnVLayout;

  QPushButton * motorForwardBtn;
  QPushButton * motorStopBtn;
  QPushButton * motorReverseOnBtn;
  QPushButton * motorReverseOffBtn;

  QPushButton * brakeEstopBtn;
  QPushButton * brakePrepareBtn;
  QPushButton * brakeReleaseBtn;
  QPushButton * brakeEngageBtn;

  QPushButton * ledNormalBtn;
  QPushButton * ledFaultBtn;

  PodNetWidget * podNetWidget;
  CircularBuffer * sendBuffer;
  CircularBuffer * sendBuffer;


public:
  MainWindow(CircularBuffer * sendBuffer,
             CircularBuffer * responseBuffer,
             QWidget *parent = nullptr);

protected:
  QSize sizeHint() const override;
  QSize minimumSizeHint() const override;
};

