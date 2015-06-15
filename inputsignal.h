#ifndef INPUTSIGNAL_H
#define INPUTSIGNAL_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class InputSignal : public QThread
{
  Q_OBJECT
public:
  explicit InputSignal(QObject *parent = 0);
  void run(void);
signals:

public slots:

private:
  QMutex mutexq;
  QWaitCondition waitq;
};

#endif // INPUTSIGNAL_H
