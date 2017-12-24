#ifndef _MAINMENU_H
#define _MAINMENU_H
#include "UI.h"

//главное меню
class mainMenu : public UI{
public:
	explicit mainMenu(SDL_Renderer*const &ren, SDL_Window*const &window);
    void show(Uint16 *const &playerName);
    int KeyEvent (SDL_KeyboardEvent & event);
    int MouseMotionEvent (SDL_MouseMotionEvent & motion);
    int MouseButtonEvent( SDL_MouseButtonEvent & button);
protected:
    void items();
};

#endif // _MAINMENU_H
