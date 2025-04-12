#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    bool invert;
    bool msb_first;
    void (*cs_pin_set)(uint8_t val);
    void (*sck_pin_set)(uint8_t val);
    void (*data_pin_set)(uint8_t val);
} sevseg_t;


void sevseg_sh(sevseg_t *local, uint8_t val);
bool sevseg_print(sevseg_t *local, char symbol);

#ifdef __cplusplus
}
#endif
