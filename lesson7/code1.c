
volatile int pinInterrupt = 2; //接中断信号的脚
volatile byte i=0; 
volatile byte income=0;  
void myfunc()
{
   if ( digitalRead(pinInterrupt) == LOW )
     Serial.println("Key UP");
   else
     Serial.println("Key UP");
}
 
void setup()
{
   Serial.begin(9600); //打开串口
   pinMode( pinInterrupt, INPUT);//设置管脚为输入
   //Enable中断管脚, 中断服务程序为onChange(), 监视引脚变化
   attachInterrupt( digitalPinToInterrupt(pinInterrupt), myfunc, CHANGE);
   pinMode(6, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
}

 
void loop()
{
   {for(i=0;i<10;i++)
    {
    income=i;
    income=income-'0';
    digitalWrite(6,income&0x1);
    digitalWrite(3,(income>>1)&0x1);
    digitalWrite(4,(income>>2)&0x1);
    digitalWrite(5,(income>>3)&0x1);
     delay(1000);
    }}
 
}


