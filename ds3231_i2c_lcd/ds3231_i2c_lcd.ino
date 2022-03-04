#include <LiquidTWI2.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>
#include <Wire.h>

DS3231 rtc(SDA, SCL);
LiquidCrystal_I2C m_lcd(0x20,16,2);
//LiquidTWI2 m_lcd(0x20,1);
void setup() {
// 初始化I2C
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  m_lcd.init();
  m_lcd.backlight();
  //lcd.begin(16, 2);
  //rtc.setDOW(SATURDAY);     
  //rtc.setTime(16, 0, 0);     
  //rtc.setDate(6, 5, 2021);

}

void loop() {

  int temp;
  temp = rtc.getTemp();
  //rtc.setDOW(SATURDAY);  
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  // Send time
  Serial.println(rtc.getTimeStr());
  Serial.print("temp = ");
  Serial.println(temp);
  // Wait one second before repeating :)
  m_lcd.setCursor(0, 0); // 设定游标位置在第一行第一个，若不设定，则依次显示
  m_lcd.print("time:");
  m_lcd.print(rtc.getDOWStr());
  m_lcd.print('-');
  m_lcd.setCursor(0,1);
  m_lcd.print("date:");
  m_lcd.print(rtc.getDateStr());
  m_lcd.setCursor(1,0);
  m_lcd.print("Tem:");
  m_lcd.print(temp);
  delay(1000);
}
