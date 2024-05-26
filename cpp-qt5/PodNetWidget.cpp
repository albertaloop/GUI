#include "PodNetWidget.h"
#include <QPainter>

PodNetWidget::PodNetWidget(QWidget *parent) : QWidget(parent)
{
}

void PodNetWidget::paintEvent(QPaintEvent * event)
{
  QPainter painter(this);
  // Draw a line from (10, 50) to (150, 50)
  
  painter.drawLine(100, 200, 500, 200);

  painter.drawRect(0, 0, 200, 160);
  painter.drawRect(240, 0, 200, 160);
  painter.drawRect(0, 240, 200, 160);
  painter.drawRect(400, 240, 200, 160);

  painter.drawLine(100, 160, 100, 200);
  painter.drawLine(340, 160, 340, 200);
  painter.drawLine(100, 200, 100, 240);
  painter.drawLine(500, 200, 500, 240);


}

QSize PodNetWidget::sizeHint() const
{
  return QSize(800,500);
}

QSize PodNetWidget::minimumSizeHint() const
{
  return QSize(800,500);
}
