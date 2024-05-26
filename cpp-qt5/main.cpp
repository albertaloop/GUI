#include <QApplication>

#include "MainWindow.h"
#include "SocketComms.h"
#include "CircularBuffer.h"

int main(int argc, char *argv[])
{

  QApplication app(argc, argv);

  CircularBuffer * buffer = new CircularBuffer(3);
  SocketComms socketComms(buffer);
  MainWindow window(buffer);
  socketComms.start();
  window.show();
  return app.exec();
}