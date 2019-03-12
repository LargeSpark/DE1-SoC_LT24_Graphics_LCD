#include "graphics.h"
void Graphics_initialise(unsigned volatile int lcd_pio_base,unsigned volatile int lcd_hw_base){
	LT24_initialise(lcd_pio_base,lcd_hw_base);
}

void Graphics_drawBox(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned short colour,bool noFill,unsigned short fillColour){
	int sx1 = (int) x1;
	int sx2 = (int) x2;
	int sy1 = (int) y1;
	int sy2 = (int) y2;
	int height = abs(sy2-sy1);
	int width = abs(sx1-sx2);
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
	if(~noFill){
		for(y=0; y <= height; y++){
			for(x=0; x<=width; x++){
				LT24_drawPixel(fillColour,x+llx,y+lly);
			}
		}
	}

	//cube outline
	//verticle outline
	for(oy = 0; oy <=height; oy++){
		LT24_drawPixel(colour,sx1,lly+oy);
	}
	for(oy = 0; oy <=height; oy++){
		LT24_drawPixel(colour,sx2,lly+oy);
	}
	//horizontal outline
	for(ox = 0; ox <=width; ox++){
		LT24_drawPixel(colour,llx+ox,sy1);
	}
	for(ox = 0; ox <=width; ox++){
		LT24_drawPixel(colour,llx+ox,sy2);
	}


}

void Graphics_drawCircle(unsigned int x,unsigned int y,unsigned int r,unsigned short colour,bool noFill,unsigned short fillColour){
	//Radius as signed int
	int signedr = (int) r;
	//Radius squared
	int rad2 = signedr * signedr;
	//Outline threshold
	int outThres = 300;
	//Go through x's
	int xc = 0;
	int yc = 0;
	//Loop through all X and Y of square the size of radius squared
	for (xc = -signedr; xc <= signedr; xc++) {
		for (yc = -signedr; yc <= signedr; yc++) {
			//radius squared = yc^2 + xc^2
			int pyr = (yc*yc) + (xc*xc);
			//If no fill then draw outline
			if(noFill && (pyr > rad2-outThres) && (pyr < rad2+outThres)){
				LT24_drawPixel(colour,xc+x,yc+y);
			}
			else if(~noFill && pyr < rad2){
				if((pyr > rad2-outThres) && (pyr < rad2+outThres)){
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

