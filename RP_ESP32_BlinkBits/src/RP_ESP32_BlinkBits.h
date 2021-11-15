/**
 *  \file RP_BlinkBits.h
 *  \brief uses timer1 and generates three blinking bits
 *  15.11.2021 by RP
 *  Header only file
 */

#ifndef RP_ESP32_BlinkBits_H_
#define RP_ESP32_BlinkBits_H_

#include <Arduino.h>

typedef struct{
  bool tm250;                           //250mS high/low
  bool tm500;                           //500mS high/low
  bool tm1000;                          //1000mS high/low
}BLINKBITS;

extern BLINKBITS blink;                 //define globally!!

hw_timer_t *RPtimer1 = NULL;            //pointer to timer function

// ----------------------------------------------------------------------------------------------------------------------------
//RPtimer1 interrupt
void IRAM_ATTR onRPtimer1(){
  static uint8_t blink_cnt;
  blink_cnt ++;
  if(blink_cnt > 15){
    blink_cnt = 0;
  }
  blink.tm250 =   blink_cnt & 0b00000001;
  blink.tm500 =   blink_cnt & 0b00000010;
  blink.tm1000 =  blink_cnt & 0b00000100;    
}

// ----------------------------------------------------------------------------------------------------------------------------
//function RPtimer1 init
void INIT_RPtimer1(void){
  RPtimer1 = timerBegin(1, 80, true);
  timerAttachInterrupt(RPtimer1, &onRPtimer1, true);
  timerAlarmWrite(RPtimer1, 250000, true);
  timerAlarmEnable(RPtimer1);
}

#endif