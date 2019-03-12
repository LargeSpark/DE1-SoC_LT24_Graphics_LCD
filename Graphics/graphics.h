#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../DE1SoC_LT24/DE1SoC_LT24.h"

 void Graphics_initialise(unsigned volatile int lcd_pio_base,unsigned volatile int lcd_hw_base);

 void Graphics_drawBox(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned short colour,bool noFill,unsigned short fillColour);

 void Graphics_drawCircle(unsigned int x,unsigned int y,unsigned int r,unsigned short colour,bool noFill,unsigned short fillColour);

 void Graphics_drawBox(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned short colour,bool noFill,unsigned short fillColour);

 void Graphics_drawLine(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned short colour);

 void Graphics_drawTriangle(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int x3,unsigned int y3,unsigned short colour,bool noFill,unsigned short fillColour);


#endif
