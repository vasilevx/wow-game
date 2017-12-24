#ifndef _INTRO_H
#define _INTRO_H
#include "UI.h"

//заставка
class intro : public UI{
public:
	explicit intro(SDL_Renderer*const &ren, SDL_Window*const &window);
};

#endif // _INTRO_H
