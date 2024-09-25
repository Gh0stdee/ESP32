#include <Arduino.h>

int sleepTime = 15;                                           //setting var for esp32 sleep time (unit: s)
int secondsConverter = 1000000;                               //convert us to s for esp sleep time function

void blink()                                                  //builtin LED blink for half a second
{
  digitalWrite(LED_BUILTIN,1); 
  delay(500);                                                 //keeping the LED on for half a second
  digitalWrite(LED_BUILTIN,0);
}

void setup() 
{
  pinMode(LED_BUILTIN,OUTPUT);                               
  blink();                                                   //signaling the ESP32 is on
  esp_sleep_enable_timer_wakeup(sleepTime*secondsConverter); //configure how long ESP will sleep
  esp_deep_sleep_start();                                    //enter deep sleep mode
}

void loop()                                                  //No code in loop as waking up after deep sleep will enter setup()
{ 
  
}
