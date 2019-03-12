#include "graphics.h"
void Graphics_initialise(unsigned volatile int lcd_pio_base,unsigned volatile int lcd_hw_base){
	LT24_initialise(lcd_pio_base,lcd_hw_base);
}

void Graphics_drawBox(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned short colour,bool noFill,unsigned short fillColour){

}

void Graphics_drawCircle(unsigned int x,unsigned int y,unsigned int r,unsigned short colour,bool noFill,unsigned short fillColour){
	//Radius Squared
	int rad2 = r * r;
	//Go through x's
	int xc; int yc;
	for (xc = -r; xc <= r; xc++) {
			for (yc = -r; yc <= r; yc++) {
				//radius squared = yc^2 + xc^2
				int pyr = (yc*yc) + (xc*xc);
					if(noFill && pyr == rad2){
						LT24_drawPixel(colour,xc+x,yc+y);
					}
					else if(~noFill && pyr < rad2){
						if(pyr == rad2){
							LT24_drawPixel(colour,xc+x,yc+y);
						}
						else{
							LT24_drawPixel(fillColour,xc+x,yc+y);
						}
					}
			}
	}

}

void Graphics_drawLine(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned short colour){

}

void Graphics_drawTriangle(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int x3,unsigned int y3,unsigned short colour,bool noFill,unsigned short fillColour){
	//Draw Outline
	Graphics_drawLine(x1,y1,x2,y2,colour);
	Graphics_drawLine(x2,y2,x3,y3,colour);
	Graphics_drawLine(x3,y3,x1,y1,colour);

	//If fill
	if(~noFill){
		//Minus 1 for each
		x1--;
		x2--;
		x3--;
		y1--;
		y2--;
		y3--;
		//int colourFinished = 0;
		//while(colourFinished == 0){

		//}
	}
}

