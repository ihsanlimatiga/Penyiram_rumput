/* --- www.nyebarilmu.com --- */
#include <Servo.h> 
#include <Wire.h>
#include <virtuabotixRTC.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int servoPin = 3; 
// Create a servo object 
Servo Servo1; 
 
//Inisialisasi pin (CLK, DAT, RST)
virtuabotixRTC myRTC(6,7,8);
 
void setup(){
//Inisialisasi port serial arduino dengan komputer
Serial.begin(9600);
Servo1.attach(servoPin); 
//penulisan data pertama kali dan disarankan saat transfer
//ke-2 ini tidak digunakan dikarenakan akan menghapus data
//sebelumnya
myRTC.setDS1302Time(00,15,20,6,04,06,2021);
//detik, menit, jam, hari dalam seminggu, tanggal, bulan, tahun
// 00:59:23 "Jumat" 10-Oktober-2017
 
lcd.begin();
lcd.setBacklight(255);
lcd.home();
//menulis tulisan awal start
lcd.setCursor(0,0);
lcd.print("Penyiram Rumput");
 
lcd.setCursor(0,1);
lcd.print("IKHSAN QADRI");
delay(2000);
lcd.clear();
}
 
void loop(){
//memanggil fungsi untuk update data waktu
myRTC.updateTime();
 
//penulisan data pada serial monitor komputer
Serial.print("Current Date / Time: ");
//fungsi penulisan data untuk tanggal
Serial.print(myRTC.dayofmonth);
 
//penulisan data "/" sebagai separator
Serial.print("/");
 
//fungsi penulisan data untuk bulan
Serial.print(myRTC.month);
 
//penulisan data "/" sebagai separator
Serial.print("/");
 
//fungsi penulisan data untuk tahun
Serial.print(myRTC.year);
 
//penulisan data untuk jarak
Serial.print(" ");
 
//fungsi penulisan data untuk jam
Serial.print(myRTC.hours);
 
Serial.print(":");
 
//fungsi penulisan data untuk menit
Serial.print(myRTC.minutes);
 
Serial.print(":");
 
//fungsi penulisan data untuk detik
Serial.println(myRTC.seconds);
 
lcd.setCursor(00,00); lcd.print(myRTC.hours);
lcd.setCursor(2,00); lcd.print(":");
lcd.setCursor(3,00); lcd.print(myRTC.minutes);
lcd.setCursor(5,00); lcd.print(":");
lcd.setCursor(6,00); lcd.print(myRTC.seconds);
 
lcd.setCursor(00, 1);lcd.print(myRTC.dayofmonth);
lcd.setCursor(2,1); lcd.print("-");
lcd.setCursor(3,1); lcd.print(myRTC.month);
lcd.setCursor(5,1); lcd.print("-");
lcd.setCursor(6,1); lcd.print(myRTC.year);

if (myRTC.seconds > 10 && myRTC.seconds < 20){
   lcd.setCursor(0,1);
   lcd.print("Sedang Menyiram");
   Servo1.write(0); 
   delay(300); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(300); 
   // Make servo go to 180 degrees 
   Servo1.write(180); 
   delay(300); 
   lcd.clear();

}

else if (myRTC.seconds > 40 && myRTC.seconds < 50){
   lcd.setCursor(0,1);
   lcd.print("Sedang Menyiram");
   Servo1.write(0); 
   delay(300); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(300); 
   // Make servo go to 180 degrees 
   Servo1.write(180); 
   delay(300); 
   lcd.clear();

}

else {
  Servo1.write(0); 
  lcd.setCursor(00, 1);lcd.print(myRTC.dayofmonth);
  lcd.setCursor(2,1); lcd.print("-");
  lcd.setCursor(3,1); lcd.print(myRTC.month);
  lcd.setCursor(5,1); lcd.print("-");
  lcd.setCursor(6,1); lcd.print(myRTC.year);
  }
/*
--- 00:59:23
--- 10-10-2017
 
 */
 
//delay(100);
 
}
 
