#pragma once

#include <QWidget>

class PodNetWidget : public QWidget
{
private:
  /* data */
  int leftBorder;
  int rightBorder;
  int topBorder;
  int bottomBorder;

  int ledX;
  int ledY;
  int stateMachineX;
  int stateMachineY;
  int brakeX;
  int brakeY;
  int motorX;
  int motorY;

  int nodeGap = 40;

  int nodeHeight = 200;
  int nodeWidth = 160;

public:
  PodNetWidget(QWidget *parent = nullptr);

protected:
  void paintEvent(QPaintEvent * event) override;
  QSize sizeHint() const override;
  QSize minimumSizeHint() const override;

};

