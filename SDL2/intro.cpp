#include "intro.h"

intro::intro(SDL_Renderer*const &ren, SDL_Window*const &window) : UI(ren, window){
    textSurface = SDL_LoadBMP("bg_intro.bmp");
	SDL_Rect r = dest;
	
	r.w = W_WIDTH;
	r.h = 200;
	r.x = 0;
	r.y = dest.h - 200;

	SDL_FillRect(textSurface, &r, SDL_MapRGB(textSurface->format, 0, 0, 0));
	r.w = W_WIDTH - 20;
	r.h = 180;
	r.x = 10;
	r.y = dest.h - 190;
	SDL_FillRect(textSurface, &r, SDL_MapRGB(textSurface->format, 8, 68, 6));

    TTF_Font * font = TTF_OpenFont("OpenSans-Regular.ttf", 72);
    text = TTF_RenderUTF8_Solid(font, "Падение Легиона", titleColor);
	r.x = (dest.w - text->w) / 2;
	r.y = dest.h - 200;
	r.w = textSurface->w;
	r.h = textSurface->h;
	SDL_BlitSurface(text, NULL, textSurface, &r);
	SDL_FreeSurface(text);
    TTF_CloseFont(font);


    text = TTF_RenderUTF8_Solid(textFont, "Васильев Н.А. И967", textColor);
	r.x = (dest.w - text->w) / 2;
	r.y = dest.h - 100;
	SDL_BlitSurface(text, NULL, textSurface, &r);
	SDL_FreeSurface(text);


    text = TTF_RenderUTF8_Solid(smallFont, "Нажмите любую клавишу", textColor);
	r.x = (dest.w - text->w) / 2;
	r.y = dest.h - 50;
	SDL_BlitSurface(text, NULL, textSurface, &r);
	SDL_FreeSurface(text);

	texture = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_FreeSurface(textSurface);
	textSurface = NULL;
	playMusic("intro_music.wav", SDL_MIX_MAXVOLUME);



}

