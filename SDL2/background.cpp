#include "background.h"

background::background(SDL_Renderer*const &ren, SDL_Window*const &window) : UI(ren, window){
	textSurface = SDL_LoadBMP("bg.bmp");
	texture = SDL_CreateTextureFromSurface(ren, textSurface);
	dest.x = 0;
	dest.y = 0;
	dest.w = textSurface->w;
	dest.h = textSurface->h;
}
