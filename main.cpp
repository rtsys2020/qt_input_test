#include <QCoreApplication>
#include "inputsignal.h"
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  InputSignal input;
  input.start();
  input.wait();
  return a.exec();
}
