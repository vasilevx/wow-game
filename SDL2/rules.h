#ifndef _RULES_H
#define _RULES_H

#include "UI.h"
//правила
class rules : public UI{
public:
	explicit rules(SDL_Renderer*const &ren, SDL_Window*const &window);
    int KeyEvent (SDL_KeyboardEvent & event);
    int MouseButtonEvent( SDL_MouseButtonEvent & button);
};

#endif // _RULES_H
