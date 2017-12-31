#ifndef _UI_H_
#define _UI_H_
#include "justSDL.h"
#include "events.h"
//интерфейс
class UI: public justSDL, public events{
protected:
    SDL_Surface* textSurface;
	SDL_Surface* text;
	TTF_Font* bigFont;
    TTF_Font* textFont;
    TTF_Font* smallFont;
	SDL_Color textColor;
    SDL_Color curTextColor;
    SDL_Color titleColor;
    int menuSwitch;
public:
	explicit UI(SDL_Renderer*const &ren, SDL_Window *const &window);
	void show();
    ~UI();
};




#endif // _UI_H_


