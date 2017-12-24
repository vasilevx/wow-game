#include "username.h"

void username::changeName(){
	SDL_Rect r = dest, rect;
	rect.x = dest.w / 4;
	rect.y = dest.h * 5 / 9;
	rect.w = dest.w / 2;
	rect.h = dest.h / 10;

    //закраска имени
	SDL_FillRect(textSurface, &rect, SDL_MapRGBA(textSurface->format, 8, 68, 6, 0));

	rect.w -= 220;
	rect.x = (dest.w - rect.w) / 2;
	rect.y = 400;
	
	rect.h = 2;

	SDL_FillRect(textSurface, &rect, SDL_MapRGBA(textSurface->format, 255, 255, 255, 0));

    if(name[0] != 0){
        text = TTF_RenderUNICODE_Solid(textFont, name, textColor);
        r.x = (dest.w - text->w) / 2; 
		r.y = dest.h * 5 / 9;
        SDL_BlitSurface(text, NULL, textSurface, &r);
        SDL_FreeSurface(text);
    }
}

username::username(SDL_Renderer*const &ren, SDL_Window *const &window, Uint16 *const &playerName) : UI(ren, window), name(playerName){
	SDL_Rect r = dest;
	
	
	text = TTF_RenderUTF8_Solid(bigFont, "ВВЕДИТЕ", titleColor);
    r.x = (dest.w - text->w) / 2; 
	r.y = dest.h / 6;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

    text = TTF_RenderUTF8_Solid(bigFont, "ИМЯ", titleColor);
    r.x = (dest.w - text->w) / 2;
	r.y += dest.h / 9;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

    changeName();

    text = TTF_RenderUTF8_Solid(smallFont, "Введите имя и нажмите Enter", textColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h - text->h;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);
}

int username::KeyEvent (SDL_Event & event){
    if(event.type==SDL_TEXTINPUT){
        Uint16 unicodeCode = event.text.text[0];
        if ((unicodeCode >= (Uint16)'a' && unicodeCode <= (Uint16)'z') ||
			(unicodeCode >= (Uint16)'A' && unicodeCode <= (Uint16)'Z') ||
			(unicodeCode >= (Uint16)'0' && unicodeCode <= (Uint16)'9'))
            if(menuSwitch<14){
                name[menuSwitch] = unicodeCode;
                menuSwitch++;
            }
            name[menuSwitch] = 0;
            changeName();

	}
	else if (event.type == SDL_KEYDOWN) {

		if (event.key.keysym.sym == SDLK_BACKSPACE)
			if (menuSwitch>0) {
				--menuSwitch;
				name[menuSwitch] = 0;
			}
		changeName();

		if (event.key.keysym.sym == SDLK_RETURN)
			return 1;
	}
    return 0;
}

void username::show() {
	if (texture) SDL_DestroyTexture(texture);
	texture = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_RenderCopy(ren, texture, nullptr, &dest);
}