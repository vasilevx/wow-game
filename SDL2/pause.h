#ifndef _PAUSE_H
#define _PAUSE_H

#include "UI.h"
//пауза
class pause : public UI{
protected:
    void item(); //пункты меню паузы
public:
	explicit pause(SDL_Renderer*const &ren, SDL_Window*const &window);
    int KeyEvent (SDL_KeyboardEvent & event);
    int MouseMotionEvent (SDL_MouseMotionEvent & motion);
    int MouseButtonEvent( SDL_MouseButtonEvent & button);
	void show();
};

#endif // _PAUSE_H
