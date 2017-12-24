#ifndef _MENUBG_H
#define _MENUBG_H

#include "UI.h"
//окно главного меню
class menuBG : public UI{
public:
	explicit menuBG(SDL_Renderer*const &ren, SDL_Window *const &window);
};

#endif // _MENUBG_H
