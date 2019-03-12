
#include "DE1SoC_LT24/DE1SoC_LT24.h"
#include "HPS_I2C/HPS_I2C.h"
#include "HPS_Watchdog/HPS_Watchdog.h"
#include "Graphics/graphics.h"
//Test code taken from assignment
//Initialise the LCD Display.
int main(void) {
 //Initialise the LCD Display.
 Graphics_initialise(0xFF200060,0xFF200080); ResetWDT();
 //Rectangle. Red Border. Grey Fill.
 Graphics_drawBox(10,10,230,310,LT24_RED,false,0x39E7); ResetWDT();
 //Circle. Blue Border, White Fill. Centre of screen. 100px radius
 Graphics_drawCircle(120,160,100,LT24_BLUE,false,LT24_MAGENTA); ResetWDT();
 //Circle. Yellow Border, No Fill. Centre of screen. 102px radius
 Graphics_drawCircle(120,160,102,LT24_YELLOW,true,0); ResetWDT();
 //Rectangle. Cyan Border, No Fill.
 Graphics_drawBox(49,89,191,231,LT24_CYAN,true,0); ResetWDT();
 //Line. Green. 45 degree Radius of circle.
 Graphics_drawLine(191,89,120,160,LT24_GREEN); ResetWDT();
 //Line. Magenta. 270 degree Radius of circle.
 Graphics_drawLine(120,160,20,160,LT24_MAGENTA); ResetWDT();
 //Triangle. Blue Border, No Fill. Bottom left corner. Right-angle triangle.
 Graphics_drawTriangle(18,283,18,302,37,302,LT24_BLUE,true,0); ResetWDT();
 //Triangle. Yellow Border, Green Fill. Bottom left corner Equilateral triangle.
 Graphics_drawTriangle(213,283,204,302,222,302,LT24_YELLOW,false,LT24_GREEN);
 //Done.
 while (1) { HPS_ResetWatchdog(); } //Watchdog reset.
}
