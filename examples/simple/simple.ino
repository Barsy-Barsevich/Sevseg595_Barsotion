#include "Sevseg595_Barsotion.h"

/**
 * A simple 7-segment via 74hc595 library
 * 
 * Available symbols:
 * Hex numbers:
 * 0 1 2 3 4 5 6 7 8 9 A b c d E F
 * Non-hex letters:
 * G H h I i J L n O o P q r S t U u Y
 * Special symbols:
 * _ - = [ ] " ' . ,
 * Space
 * 
 * 7-segment & 74hc595 wiring:
 * msb_first = true:
 * |Q0|Q1|Q2|Q3|Q4|Q5|Q6|Q7|
 * |A |B |C |D |E |F |G |DP|
 * msb_first = false:
 * |Q0|Q1|Q2|Q3|Q4|Q5|Q6|Q7|
 * |DP|G |F |E |D |C |B |A |
 * 
 * Common cathode - invert = false
 * Common anode - invert = true
 */


const int cs = 6;  //RCLK - 12 pin
const int sck = 5; //SRCLK - 11 pin
const int d = 4;   //SER - 14 pin

void cs_set(uint8_t val) {digitalWrite(cs, val);}
void sck_set(uint8_t val) {digitalWrite(sck, val);}
void data_set(uint8_t val) {digitalWrite(d, val);}

sevseg_t sevseg;


void setup()
{
    pinMode(cs, OUTPUT);
    pinMode(sck, OUTPUT);
    pinMode(d, OUTPUT);
    sevseg.msb_first = true;
    sevseg.invert = false; //common cathode
    sevseg.cs_pin_set = cs_set;
    sevseg.sck_pin_set = sck_set;
    sevseg.data_pin_set = data_set;
}

void loop()
{
    sevseg_print(&sevseg, '0'); //printing hex-numbers
    delay(500);
    sevseg_print(&sevseg, '1');
    delay(500);
    sevseg_print(&sevseg, 'A');
    delay(500);
    sevseg_print(&sevseg, 'Y'); //printing non-hex letters
    delay(500);
    sevseg_print(&sevseg, 'Q');
    delay(500);
    sevseg_print(&sevseg, '-'); //printing special symbols
    delay(500);
    sevseg_print(&sevseg, '=');
    delay(500);
    sevseg_print(&sevseg, '_');
    delay(500);
    sevseg_print(&sevseg, ' '); //printing a space
    delay(2000);
}
