#include "display.h"
#include <avr/pgmspace.h>

Display display;

const int *const lineData[] PROGMEM = {  // character (number of points + starting offset)
  1, 0, 2, 0, 0, 1, 0, 6, 3, 1, 3, 6, 1, 4, 2, 4, // A
  0, 0, 0, 6, 1, 0, 2, 0, 1, 3, 2, 3, 1, 6, 2, 6, 3, 1, 3, 2, 3, 4, 3, 5, // B
  0, 1, 0, 5, 1, 0, 2, 0, 3, 1, 3, 1, 1, 6, 2, 6, 3, 5, 3, 5, // C
  0, 0, 0, 6, 1, 0, 2, 0, 1, 6, 2, 6, 3, 1, 3, 5, // D
  0, 0, 0, 6, 1, 0, 3, 0, 1, 3, 2, 3, 1, 6, 3, 6,  // E
  0, 0, 0, 6, 1, 0, 3, 0, 1, 3, 2, 3,  // F
  0, 1, 0, 5, 1, 0, 2, 0, 3, 1, 3, 1, 1, 6, 2, 6, 3, 3, 3, 5, 2, 3, 2, 3, // G
  0, 0, 0, 6, 1, 3, 2, 3, 3, 0, 3, 6,  // H
  0, 0, 0, 6, // I
  3, 0, 3, 5, 2, 6, 1, 6, 0, 5, 0, 5,  // J
  0, 0, 0, 6, 1, 2, 1, 2, 2, 1, 2, 1, 3, 0, 3, 0, 1, 4, 1, 4, 2, 5, 2, 5, 3, 6, 3, 6,  // K
  0, 0, 0, 6, 1, 6, 3, 6, // L
  0, 0, 0, 6, 1, 1, 1, 1, 2, 2, 2, 2, 3, 1, 3, 1, 4, 0, 4, 6, // M
  0, 0, 0, 6, 1, 0, 1, 1, 2, 2, 2, 4, 3, 5, 3, 6, 4, 0, 4, 6, // N
  0, 1, 0, 5, 1, 0, 2, 0, 3, 1, 3, 5, 1, 6, 2, 6, // O
  0, 0, 0, 6, 1, 0, 2, 0, 1, 3, 2, 3, 3, 1, 3, 2, // P
  0, 1, 0, 5, 1, 0, 2, 0, 1, 6, 1, 6, 3, 1, 3, 4, 2, 5, 2, 5, 3, 6, 3, 6, // Q
  0, 0, 0, 6, 1, 0, 2, 0, 1, 3, 2, 3, 3, 1, 3, 2, 1, 4, 1, 4, 2, 5, 2, 5, 3, 6, 3, 6, // R
  3, 1, 3, 1, 2, 0, 1, 0, 0, 1, 0, 2, 1, 3, 2, 3, 3, 4, 3, 5, 2, 6, 1, 6, 0, 5, 0, 5, // S
  0, 0, 4, 0, 2, 1, 2, 6, // T
  0, 0, 0, 5, 1, 6, 2, 6, 3, 0, 3, 5, // U
  2, 6, 2, 5, 1, 4, 1, 2, 0, 1, 0, 0, 3, 4, 3, 2, 4, 1, 4, 0, // V
  0, 0, 0, 6, 1, 5, 1, 5, 2, 4, 2, 4, 3, 5, 3, 5, 4, 6, 4, 6, 4, 5, 4, 0, // W
  1, 2, 1, 2, 2, 3, 2, 3, 3, 4, 3, 4, 3, 2, 3, 2, 1, 4, 1, 4, 0, 0, 0, 1, 4, 0, 4, 1, 0, 5, 0, 6, 4, 5, 4, 6,  // X
  2, 6, 2, 3, 1, 3, 1, 2, 0, 1, 0, 0, 3, 3, 3, 2, 4, 1, 4, 0, // Y
  0, 0, 3, 0, 3, 1, 3, 1, 2, 2, 2, 2, 1, 3, 1, 3, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 3, 6, // Z
  0, 1, 0, 5, 1, 0, 2, 0, 3, 1, 3, 5, 1, 6, 2, 6, // 0
  0, 1, 0, 1, 1, 0, 1, 5, 0, 6, 2, 6, // 1
  0, 1, 0, 1, 1, 0, 2, 0, 3, 1, 3, 2, 2, 3, 2, 3, 1, 4, 1, 4, 0, 5, 0, 5, 0, 6, 0, 6, 1, 6, 3, 6, // 2
  0, 1, 0, 1, 1, 0, 2, 0, 3, 1, 3, 2, 1, 3, 2, 3, 3, 4, 3, 5, 1, 6, 2, 6, 0, 5, 0, 5, // 3
  4, 4, 4, 4, 3, 6, 3, 0, 2, 4, 0, 4, 0, 3, 0, 3, 1, 2, 1, 2, 2, 1, 2, 1, 3, 0, 3, 0, // 4
  3, 0, 0, 0, 0, 1, 0, 2, 1, 2, 2, 2, 3, 3, 3, 5, 2, 6, 1, 6, 0, 5, 0, 5, // 5
  3, 1, 3, 1, 2, 0, 1, 0, 0, 1, 0, 5, 1, 6, 2, 6, 3, 5, 3, 4, 2, 3, 1, 3, // 6
  0, 0, 3, 0, 3, 1, 3, 2, 2, 3, 2, 4, 1, 5, 1, 6, // 7
  1, 0, 2, 0, 0, 1, 0, 2, 3, 1, 3, 2, 1, 3, 2, 3, 0, 4, 0, 5, 3, 4, 3, 5, 1, 6, 2, 6, // 8
  0, 1, 0, 2, 1, 0, 2, 0, 3, 1, 3, 5, 1, 3, 2, 3, 1, 6, 2, 6, // 9
  0, 0, 0, 0, // space
  0, 0, 0, 0, 2, 0, 2, 0, 1, 1, 1, 1, 0, 2, 0, 2, 2, 2, 2, 2, 1, 3, 1, 3, 0, 4, 0, 4, 2, 4, 2, 4, 1, 5, 1, 5, 0, 6, 0, 6, 2, 6, 2, 6, // unknown
  0, 5, 0, 6, 1, 5, 1, 6,  // .
  0, 4, 0, 5, 0, 1, 0, 2,  // :
};

// String format: Symbol (first character), number of lines (next 2 digits), width (next digit), starting line data offset (last 4 digits)
const int LENGTH_OF_CHAR_DATA = 8;
const char *const characterData[320] PROGMEM = {
// X indicates that I have not seen how this character is rendered on the real unit
'A','0','4','4','0','0','0','0',
'B','0','6','4','0','0','1','6',   // X
'C','0','5','4','0','0','4','0',
'D','0','4','4','0','0','6','0',   // X
'E','0','4','4','0','0','7','6',
'F','0','3','4','0','0','9','2',   // X
'G','0','6','4','0','1','0','4',
'H','0','3','4','0','1','2','8',
'I','0','1','1','0','1','4','0',
'J','0','3','4','0','1','4','4',  // X
'K','0','7','4','0','1','5','6',
'L','0','2','4','0','1','8','4',
'M','0','5','5','0','1','9','2',
'N','0','5','5','0','2','0','8',
'O','0','4','4','0','2','3','2',
'P','0','4','4','0','2','4','8',
'Q','0','6','4','0','2','6','4',
'R','0','7','4','0','2','8','8',
'S','0','7','4','0','3','1','6',
'T','0','2','5','0','3','4','4',
'U','0','3','4','0','3','5','2',
'V','0','5','5','0','3','6','4',
'W','0','6','5','0','3','8','4',  // X
'X','0','9','5','0','4','0','8',  // X
'Y','0','5','5','0','4','4','4',
'Z','0','7','4','0','4','6','4',
'0','0','4','4','0','4','9','2', // X
'1','0','3','3','0','5','0','8', // X
'2','0','8','4','0','5','2','0', // X
'3','0','7','4','0','5','5','2',
'4','0','7','5','0','5','8','0', // X
'5','0','6','4','0','6','0','8', // X
'6','0','6','4','0','6','3','2', // X
'7','0','4','4','0','6','5','6', // X
'8','0','7','4','0','6','7','2', // X
'9','0','5','4','0','7','0','0',
' ','0','0','1','0','7','2','0',
'\0','1','1','3','0','7','2','4',
'.','0','2','2','0','7','6','8',
':','0','2','1','0','7','7','6',
};

struct Map {
  int getCharacterData(char character) {
    for (int i = 0; i < sizeof(characterData) / sizeof(char*); i += 8) {
      if (pgm_read_word(&characterData[i]) == character) {
        return i;
      }
    }
    display.setCursor(0, 18);
    display.setTextColor(0xFF000);
    display.setTextSize(1);
    display.printText("ERROR");
    display.setCursor(0, 26);
    display.printText("UNKNOWN CHAR");
    return 724;
  }
};
