#include "UI.h"
UI::UI(SDL_Renderer*const &ren, SDL_Window*const &window) : text(NULL), menuSwitch(0){
	this->ren = ren;
	texture = NULL;


	SDL_Surface *tempWindowSurface = SDL_GetWindowSurface(window);
	textSurface = SDL_CreateRGBSurface(0, tempWindowSurface->w, tempWindowSurface->h, 32, tempWindowSurface->format->Rmask, tempWindowSurface->format->Gmask, tempWindowSurface->format->Bmask, tempWindowSurface->format->Amask);
	
	SDL_Rect rect;
	rect.x = 0; rect.y = 0; rect.w = W_WIDTH; rect.h = W_HEIGHT;
	SDL_FillRect(textSurface, &rect, SDL_MapRGB(textSurface->format, 180, 180, 180));
	SDL_SetColorKey(textSurface, SDL_TRUE, SDL_MapRGBA(textSurface->format, 180, 180, 180, 255));
	SDL_SetColorKey(textSurface, 1, SDL_MapRGB(textSurface->format, 180, 180, 180));

	dest.w = tempWindowSurface->w;
	dest.h = tempWindowSurface->h;
	
	bigFont = TTF_OpenFont("OpenSans-Regular.ttf", 64); /* Заголовок */
    textFont = TTF_OpenFont("OpenSans-Regular.ttf", 32); /* Текст */
    smallFont = TTF_OpenFont("OpenSans-Regular.ttf", 26); /* Подсказки */

    textColor.r = 255; textColor.g = 255; textColor.b = 255; /* Основной */
    curTextColor.r = 0; curTextColor.g = 0; curTextColor.b = 0; /* Задействованный */
    titleColor.r = 255; titleColor.g = 213; titleColor.b = 0;
}

void UI::show(){
	dest.x = 0;
	dest.y = 0;
	if (!texture) 
		texture = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_RenderCopy(ren, texture, nullptr, &dest);
}

UI::~UI(){
    //TTF_CloseFont(bigFont);
    //TTF_CloseFont(textFont);
    //TTF_CloseFont(smallFont);
    textSurface = NULL;
}
