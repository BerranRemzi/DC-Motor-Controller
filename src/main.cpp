#include <Arduino.h>

#include <Button.h>
#include <Pwm.h>
#include <SevSeg.h>
#include <Menu.h>
#include <Watchdog.h>
#include <SoftTimer.h>

/**
 * Put your setup code here, to run once
 */
void setup()
{
  Button_Init();
  Pwm_Init();
  SevSeg_Init();
  Menu_Init();
  SoftTimer_Init();
  Watchdog_Init();
}

/**
 * Put your main code here, to run repeatedly
 */
void loop()
{
  SoftTimer_Task();
}