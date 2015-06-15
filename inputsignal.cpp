#include "inputsignal.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>

InputSignal::InputSignal(QObject *parent) :
  QThread(parent)
{
}


void InputSignal::run()
{
  FILE *fp_input;
  int buttons_fd,butt,val;
  int current_buttons[4],curr[4],stat[4];
  for(int i=0;i<4;i++)
    {
      stat[i]=255;
    }
  //buttons_fd = open("/dev/event0", 0);
  fp_input = fopen("/dev/event0","r");
//  if (buttons_fd < 0) {
//          printf("err open device buttons\n");
//          return;
//  }
  if(fp_input == NULL)
    {
      printf("can not open\n");
    }
  while(1)
    {
      mutexq.lock();
      waitq.wait(&mutexq,1);
      fread(current_buttons,sizeof(current_buttons),1,fp_input);
      butt=(current_buttons[2]&0x00ff0000)>>16;
      val = current_buttons[3];
      printf("#######key:%d , val:%d###########\n",butt,val);
      if(butt == 1 && val != stat[0])
        {
          //button 1 press
          printf("butt 1 :%d\n",val);
          stat[0]=val;
        }
      if(butt == 2 && val != stat[1])
        {
          //button 1 press
          printf("butt 2 :%d\n",val);
          stat[1]=val;
        }
      if(butt == 3 && val != stat[2])
        {
          //button 1 press
          printf("butt 3 :%d\n",val);
          stat[2]=val;
        }
      if(butt == 4 && val != stat[3])
        {
          //button 1 press
          printf("butt 4 :%d\n",val);
          stat[3]=val;
        }
      mutexq.unlock();
    }
}
