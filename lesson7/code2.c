#include <MsTimer2.h>     //定时器库的头文件
int tick = 0; 
byte income1 = 0;
int pinInterrupt = 2;
//中断服务程序
void onChange()
{
  if( digitalRead(pinInterrupt)==LOW)
  {
    tick=-1;
    MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
    MsTimer2::start(); //开始计时
  }
  else
  {
    tick=-1;
    MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
    MsTimer2::start(); //开始计时
  } 
}
void onTimer()
{
  tick=tick+1;
  if(tick>9)
    tick=0;
  Serial.print("time����");   
  Serial.println(tick);
  income1=tick;
  digitalWrite(3,income1&0x1);
  digitalWrite(4,(income1>>1)&0x1);
  digitalWrite(5,(income1>>2)&0x1);
  digitalWrite(6,(income1>>3)&0x1);
}
 
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(pinInterrupt, INPUT);
  Serial.begin(9600); 
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
  MsTimer2::set(1000, onTimer);
  MsTimer2::start(); 
}
void loop()
{ 
}
