
#include <LiquidCrystal.h>
#include <OneWire.h>
OneWire  ds(9);
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);
int ruchka;
byte symbol=0;
void setup() {
  lcd.begin(16, 2);
  lcd.print("sasha");
}
void loop() {
   byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius, fahrenheit;
  
  if ( !ds.search(addr)) {
    Serial.println("No more addresses.");
    Serial.println();
    ds.reset_search();
    delay(250);
    return;
  }
   
  Serial.print("ROM =");
  for( i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(addr[i], HEX);
  }

  if (OneWire::crc8(addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return;
  }
  Serial.println();
 
  // the first ROM byte indicates which chip
  switch (addr[0]) {
    case 0x10:
      Serial.println("  Chip = DS18S20");  // or old DS1820
      type_s = 1;
      break;
    case 0x28:
      Serial.println("  Chip = DS18B20");
      type_s = 0;
      break;
    case 0x22:
      Serial.println("  Chip = DS1822");
      type_s = 0;
      break;
    default:
      Serial.println("Device is not a DS18x20 family device.");
      return;
  } 
  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);    
    
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);    
  for ( i = 0; i < 9; i++) {
    data[i] = ds.read();
  }
  Serial.print(" CRC=");
  Serial.print(OneWire::crc8(data, 8), HEX);
  Serial.println();
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; 
    if (data[7] == 0x10) {
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw & ~7;  
    else if (cfg == 0x20) raw = raw & ~3; 
    else if (cfg == 0x40) raw = raw & ~1; 
  celsius = (float)raw / 16.0;
  lcd.clear();
  lcd.home();
  lcd.print("temperature");
  lcd.print(celsius);
  ruchka=analogRead(14);
  ruchka=ruchka*15/1023;
  lcd.setCursor(0, 1);
  
  for (int r=0; r<=ruchka; r++)
  lcd.print("\xFF");
}
 delay(100);
}
