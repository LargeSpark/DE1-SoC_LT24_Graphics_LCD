#include "graphics.h"
void Graphics_initialise(unsigned volatile int lcd_pio_base,unsigned volatile int lcd_hw_base){
	LT24_initialise(lcd_pio_base,lcd_hw_base);
}

void Graphics_drawBox(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned short colour,bool noFill,unsigned short fillColour){
	//Signed Values declares
	int sx1 = (int) x1;
	int sx2 = (int) x2;
	int sy1 = (int) y1;
	int sy2 = (int) y2;
	//calculate height and width
	int height = abs(sy2-sy1);
	int width = abs(sx1-sx2);
	//set values for forloops
	int y=0;
	int x=0;
	int oy=0;
	int ox=0;

	//find bottom left value
	int llx = 0;
	int lly = 0;
	if(sx1<sx2){
		llx = sx1;
	}
	else{
		llx = sx2;
	}

	if(sy1<sy2){
		lly = sy1;
	}
	else{
		lly = sy2;
	}

	//cube fill (draws first so it can be overdrawn with outline)
	if(!noFill){
		for(y=0; y <= height; y++){
			for(x=0; x<=width; x++){
				Graphics_drawPixel(fillColour,x+llx,y+lly);
			}
		}
	}

	//cube outline
	//verticle outline
	for(oy = 0; oy <=height; oy++){
		Graphics_drawPixel(colour,sx1,lly+oy);
	}
	for(oy = 0; oy <=height; oy++){
		Graphics_drawPixel(colour,sx2,lly+oy);
	}
	//horizontal outline
	for(ox = 0; ox <=width; ox++){
		Graphics_drawPixel(colour,llx+ox,sy1);
	}
	for(ox = 0; ox <=width; ox++){
		Graphics_drawPixel(colour,llx+ox,sy2);
	}


}

void Graphics_drawCircle(unsigned int x,unsigned int y,unsigned int r,unsigned short colour,bool noFill,unsigned short fillColour){
	//Radius as signed int
	int signedr = (int) r;
	//Radius squared
	int rad2 = signedr * signedr;
	//Outline threshold
	int outThres = 230;
	//Go through x's
	int xc = 0;
	int yc = 0;
	//Loop through all X and Y of square the size of radius squared
	for (xc = -signedr-3; xc <= signedr + 3; xc++) {
		for (yc = -signedr-3; yc <= signedr + 3; yc++) {
			//radius squared = yc^2 + xc^2
			int pyr = (yc*yc) + (xc*xc);
			//If no fill then draw outline
			if(noFill && (pyr > rad2-outThres) && (pyr <= rad2)){
				Graphics_drawPixel(colour,xc+x,yc+y);
			}
			//If fill draw fill
			else if(!noFill && pyr <= rad2){
				Graphics_drawPixel(fillColour,xc+x,yc+y);
			}
		}
	}
	//if fill draw outline last over fill
	if(~noFill){
		xc = 0;
		yc = 0;
		for (xc = -signedr-3; xc <= signedr+3; xc++) {
			for (yc = -signedr-3; yc <= signedr+3; yc++) {
				//get r and check if it the same as radius
				int pyr = (yc*yc) + (xc*xc);
				if((pyr > rad2-outThres) && (pyr <= rad2)){
					LT24_drawPixel(colour,xc+x,yc+y);
				}
			}
		}
	}

}

void Graphics_drawLine(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned short colour){
	//REFERENCE: drawLine using Bresenhams algorithm. https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm

	//calculate deltas
	int dx =  abs (x2 - x1);
	int dy = -abs (y2 - y1);
	//calculate error
	int error = dx + dy;
	int error2;
	//Find quadrant
	int sy;
	int sx;
	if(x1<x2){
		sx = 1;
	}
	else{
		sx = -1;
	}

	if(y1<y2){
		sy = 1;
	}
	else{
		sy = -1;
	}
	//Loop though and calculate line pixels
	while(1){
		Graphics_drawPixel(colour,x1,y1);
		if (x1 == x2 && y1 == y2){ break;}
		error2 = 2 * error;
		//if error2 is larger than delta y then add 1 to x
		if (error2 >= dy) {
			error += dy;
			x1 += sx;
		}
		//if error2 is smaller than delta x then add 1 to y
		if (error2 <= dx) {
			error += dx;
			y1 += sy;
		}
  }
}

void Graphics_drawTriangle(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int x3,unsigned int y3,unsigned short colour,bool noFill,unsigned short fillColour){

	//If fill
	if(!noFill){
		//Run fill traingle on 3 occassions to ensure on small triangles that no pixel is missed. Reset WD.
		Graphics_fillTriangle(x1,y1,x2,y2,x3,y3,fillColour);ResetWDT();
		Graphics_fillTriangle(x3,y3,x1,y1,x2,y2,fillColour);ResetWDT();
		Graphics_fillTriangle(x2,y2,x3,y3,x1,y1,fillColour);ResetWDT();
	}
	//Draw Outline
	Graphics_drawLine(x1,y1,x2,y2,colour);
	Graphics_drawLine(x2,y2,x3,y3,colour);
	Graphics_drawLine(x3,y3,x1,y1,colour);
}

void Graphics_fillTriangle(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int x3,unsigned int y3,unsigned short fillColour){
	//A rewrite of the straight line function to allow it to drawlines to fill the trangle.
	//calculate deltas
		int dx =  abs (x2 - x1);
		int dy = -abs (y2 - y1);
		//calculate error
		int error = dx + dy;
		int error2;
		int sy;
		int sx;
		if(x1<x2){
			sx = 1;
		}
		else{
			sx = -1;
		}

		if(y1<y2){
			sy = 1;
		}
		else{
			sy = -1;
		}
		while(1){
			Graphics_drawLine(x3,y3,x1,y1,fillColour); //drawLine
		    if (x1 == x2 && y1 == y2){ break;}
		    error2 = 2 * error;
		    if (error2 >= dy) {
		    	error += dy;
		    	x1 += sx;
		    }
		    if (error2 <= dx) {
		    	error += dx;
		    	y1 += sy;
		    }
		}
}

void Graphics_drawPixel(unsigned short Colour, unsigned int x, unsigned int y){
	int status = LT24_drawPixel(Colour,x,y);
	ResetWDT();
	if(status != 0){
		SDisplay_clearAll();
		SDisplay_set(0, 0x1);
		SDisplay_set(1, 0xE);
	}
}
