#include "menuBG.h"

menuBG::menuBG(SDL_Renderer *const &ren, SDL_Window *const &window) : UI(ren, window){
	SDL_Rect r;
	r.w = 520;
    r.h = 520;
	r.x = (dest.w-500)/2-10;
    r.y = 90;

	SDL_FillRect(textSurface, &r, SDL_MapRGB(textSurface->format, 0, 0, 0));
	r.w = 500;
	r.h = 500;
	r.x = (dest.w - 500) / 2;
	r.y = 100;
	SDL_FillRect(textSurface, &r, SDL_MapRGB(textSurface->format, 8, 68, 6));
}
