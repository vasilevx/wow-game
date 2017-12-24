#include "gameOver.h"

gameOver::gameOver(SDL_Renderer *const &ren, SDL_Window *const &window) : UI(ren, window){
	SDL_Rect r = dest;
    text = TTF_RenderUTF8_Solid(bigFont, "ИГРА ОКОНЧЕНА", titleColor);
    r.x = (dest.w - text->w) / 2; 
	r.y = dest.h / 6;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);


    text = TTF_RenderUTF8_Solid(smallFont, "Нажмите Enter", textColor);
    r.x = (dest.w - text->w) / 2; 
	r.y = dest.h - text->h-20;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);
}

void gameOver::show(Uint16 *const &playerName, int score){
	SDL_Rect r = dest;
	r.x = (dest.w - text->w) / 2;
	r.y = dest.h / 3;
	r.w = text->w;
	r.h = text->h;

    if(playerName[0] != 0){
        text = TTF_RenderUNICODE_Solid(textFont, playerName, textColor);
        r.x = (dest.w - text->w) / 2; 
		r.y = dest.h / 3;
		r.w = text->w;
		r.h = text->h;
		SDL_Texture *tText = SDL_CreateTextureFromSurface(ren, text);
		SDL_FreeSurface(text);
		SDL_RenderCopy(ren, tText, nullptr, &r);
		SDL_DestroyTexture(tText);
    }

    char txtbuf[100];
    memset(txtbuf,0,100);
    sprintf_s(txtbuf, "%d", score);
    text = TTF_RenderUTF8_Solid(textFont, txtbuf, textColor);
	r.x = (dest.w - text->w) / 2;
    r.y = dest.h * 4 / 9;
	r.w = text->w;
	r.h = text->h;

	SDL_Texture *tText = SDL_CreateTextureFromSurface(ren, text);
	SDL_FreeSurface(text);
	SDL_RenderCopy(ren, tText, nullptr, &r);
	SDL_DestroyTexture(tText);

	if (texture) SDL_DestroyTexture(texture);
	texture = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_RenderCopy(ren, texture, nullptr, &dest);


}
