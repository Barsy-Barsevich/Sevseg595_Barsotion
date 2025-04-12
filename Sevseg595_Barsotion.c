#include "Sevseg595_Barsotion.h"


static const uint8_t sevseg_arr[] = 
{
    0b11111100, // 0
    0b01100000, // 1
    0b11011010, // 2
    0b11110010, // 3
    0b01100110, // 4
    0b10110110, // 5
    0b10111110, // 6
    0b11100000, // 7
    0b11111110, // 8
    0b11110110, // 9
    0b11101110, // A
    0b00111110, // b
    0b00011010, // c
    0b01111010, // d
    0b10011110, // E
    0b10001110, // F
    0b10111100, // G
    0b01101110, // H
    0b00101110, // h
    0b01100000, // I
    0b00100000, // i
    0b11111000, // J
    0b00011100, // L
    0b00101010, // n
    0b11111100, // O
    0b00111010, // o
    0b11001110, // P
    0b11100110, // Q
    0b00001010, // r
    0b10110110, // S
    0b00011110, // t
    0b01111100, // U
    0b00111000, // u
    0b01110110, // Y
    0b00010000, // _
    0b00000010, // -
    0b00010010, // =
    0b10011100, // [
    0b11110000, // ]
    0b01000100, // "
    0b00010000, // '
    0b00000001, // .
    0b00000001, // ,
};


void sevseg_sh(sevseg_t *local, uint8_t val)
{
    local->cs_pin_set(0);
    if (local->msb_first)
    {
        for (int8_t i=0; i<8; i++)
        {
            local->sck_pin_set(0);
            local->data_pin_set((val>>i)&1);
            local->sck_pin_set(1);
        }
    }
    else
    {
        for (int8_t i=7; i>=0; i--)
        {
            local->sck_pin_set(0);
            local->data_pin_set((val>>i)&1);
            local->sck_pin_set(1);
        }
    }
    local->cs_pin_set(1);
}

bool sevseg_print(sevseg_t *local, char symbol)
{
    bool correct_symbol = true;
    uint8_t code = 0;
    if ((symbol >= '0') && (symbol <= '9'))
    {
        code = sevseg_arr[symbol-0x30];
    }
    else if ((symbol >= 'A') && (symbol <= 'H'))
    {
        code = sevseg_arr[symbol-0x30-7];
    }
    else
    {
        switch (symbol)
        {
            case 'a': code = sevseg_arr[0xa]; break;
            case 'b': code = sevseg_arr[0xb]; break;
            case 'c': code = sevseg_arr[0xc]; break;
            case 'd': code = sevseg_arr[0xd]; break;
            case 'e': code = sevseg_arr[0xe]; break;
            case 'f': code = sevseg_arr[0xf]; break;
            case 'g': code = sevseg_arr[16]; break;
            case 'h': code = sevseg_arr[18]; break;
            case 'I': code = sevseg_arr[19]; break;
            case 'i': code = sevseg_arr[20]; break;
            case 'J': code = sevseg_arr[21]; break;
            case 'j': code = sevseg_arr[21]; break;
            case 'L': code = sevseg_arr[22]; break;
            case 'N': code = sevseg_arr[23]; break;
            case 'n': code = sevseg_arr[23]; break;
            case 'O': code = sevseg_arr[24]; break;
            case 'o': code = sevseg_arr[25]; break;
            case 'P': code = sevseg_arr[26]; break;
            case 'Q': code = sevseg_arr[27]; break;
            case 'q': code = sevseg_arr[27]; break;
            case 'R': code = sevseg_arr[28]; break;
            case 'r': code = sevseg_arr[28]; break;
            case 'S': code = sevseg_arr[29]; break;
            case 's': code = sevseg_arr[29]; break;
            case 'T': code = sevseg_arr[30]; break;
            case 't': code = sevseg_arr[30]; break;
            case 'U': code = sevseg_arr[31]; break;
            case 'u': code = sevseg_arr[32]; break;
            case 'Y': code = sevseg_arr[33]; break;
            case 'y': code = sevseg_arr[33]; break;
            case '_': code = sevseg_arr[34]; break;
            case '-': code = sevseg_arr[35]; break;
            case '=': code = sevseg_arr[36]; break;
            case '[': code = sevseg_arr[37]; break;
            case ']': code = sevseg_arr[38]; break;
            case '"': code = sevseg_arr[39]; break;
            case /*'''*/39: code = sevseg_arr[40]; break;
            case '.': code = sevseg_arr[41]; break;
            case ',': code = sevseg_arr[42]; break;
            case ' ': code = 0; break;
            default: code = 0b00000001; correct_symbol = false;
        }
    }
    if (correct_symbol)
    {
        if (local->invert) code = ~code;
        sevseg_sh(local, code);
    }
    return correct_symbol;
}
