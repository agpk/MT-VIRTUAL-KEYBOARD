# MT-VIRTUAL-KEYBOARD
a open-source minimal standalone virtual keyboard for the M5StickC
# Implement
1. Add the <'mt'> folder in your Arduino project directory.
<ALT> 1. Add the <'mt'> folder as a library.
2. Include the standard M5StickC in your main project file.
3. Include Mt library as a library or a local program file.
4. Declare a defined char-array in a local variable.
5. Use the <'OPEN_MT'> command with you declared variable
with a brief user text for indicate type of the input.
# Example
``` cpp
#include <M5StickC.h>
#include "mt/mtvk.h"

void setup() {
  M5.begin();
  char H[0xFF];
  OPEN_MT(H,"INPUT:");
  M5.Lcd.printf("%s",H);
}
```
# Using
- Simple one-push of the <'A'> M5StickC's button for increment the char pointer.
- Simple one-push of the <'B'> M5StickC's button for decrement the char pointer.
- Press the <'A'> M5StickC's button for one demi-second for validate the current char pointer.
- Press the <'B'> M5StickC's button for one second for validate the entire-typed string and exit.
