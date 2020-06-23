#include <MsTimer2.h>     //定时器库的头文件
 
int tick = 0; //计数值
 
//中断服务程序
byte income=0;
void onTimer()
{
   int i;
    {for(i=0;i<10;i++)
    {
    income=i;
    income=income-'0';
    digitalWrite(2,income&0x1);
    digitalWrite(3,(income>>1)&0x1);
    digitalWrite(4,(income>>2)&0x1);
    digitalWrite(5,(income>>3)&0x1);
    delay(1000);
    }}
}
 
void setup()
{
  Serial.begin(9600); //初始化串口
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
}
 
void loop()
{
  
}
