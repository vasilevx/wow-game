#ifndef _USERNAME_H
#define _USERNAME_H

#include "UI.h"
//имя пользователя
class username : public UI{
protected:
    Uint16 *name;
    void changeName();
public:
	username(SDL_Renderer*const &ren, SDL_Window*const &window, Uint16 *const &playerName);
	void show();
    int KeyEvent (SDL_Event & event);
};

#endif // _USERNAME_H
