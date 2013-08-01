#include <plib.h>
#include "NU32.h"

int main(void) {
    startup(); // set NU32 to maximum speed
    while(1)
    {
        int j;
        for (j=0; j<4000000; j++) {}
        while(user_switch_pressed());
        NU32LED1 = !NU32LED1;
        NU32LED2 = !NU32LED2;
    }
    return 0;
}