
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins(//用接口引脚的数字初始化库)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:(设置LCD的列数和行数:)
  lcd.begin(16, 2);//(定义LCD的长宽（16列×2行)
  // Print a message to the LCD.(打印一条信息到液晶屏上。)
  lcd.print("hello, world!");//(打印“helllo world”)
}

void loop() {
  // set the cursor to column 0, line 1（将光标设置为列0，第1行）
  // (note: line 1 is the second row, since counting begins with 0):(注意:第一行是第二行，因为计数从0开始):)
  lcd.setCursor(0, 1);//移动光标到特定位置 第1行第0列
  // print the number of seconds since reset:(打印重置以来的秒数))
  lcd.print(millis() / 1000);//开机1000毫秒
}
 