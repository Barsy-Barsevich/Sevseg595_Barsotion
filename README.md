# Sevseg595
A simple library for 7-segment display driven by 74HC595 shift register
- Arduino-compatible

## Usage
### `sevseg_t`
A library structure-descriptor.
#### Fields:
- `bool invert` - set 'true', if the indicator has common cathode, 'false' if common anode;
- `bool msb_first` - sets the bit shifting ordering, [7-segment display & 74HC595 wiring](#7-segment-display-&-74HC595-wiring)
- `void (\*cs_pin_set)(uint8_t val)` - a pointer to function driving cs (RCLK, 12) pin;
- `void (\*sck_pin_set)(uint8_t val)` - a pointer to function driving sck (SRCLK, 11) pin;
- `void (\*data_pin_set)(uint8_t val)` - a pointer to function driving data (SER, 14) pin;

### `bool sevseg_print(sevseg_t *local, char symbol)`
Prints value `symbol` to the display.
- local - a pointer to structure-descriptor;
- symbol - ASCII-symbol

## 7 segment display & 74HC595 wiring
The wiring depends on `msb_first` value of structure-descriptor.
### `msb_first == true`
| Q0  | Q1  | Q2  | Q3  | Q4  | Q5  | Q6  | Q7  |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-:|
| A   | B   | C   | D   | E   | F   | G   | DP  |
### `msb_first == false`
| Q0  | Q1  | Q2  | Q3  | Q4  | Q5  | Q6  | Q7  |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-:|
| DP  |  G  |  F  |  E  |  D  |  C  |  B  |  A  |

## Allowed symbols
 - Hex numbers: 0 1 2 3 4 5 6 7 8 9 A b c d E F
 - Non-hex letters: G H h I i J L n O o P q r S t U u Y
 - Special symbols: _ - = [ ] " ' . ,
 - Space