#ifndef _GAMEOVER_H
#define _GAMEOVER_H

#include "UI.h"

//окончание игры
class gameOver : public UI{
public:
	explicit gameOver(SDL_Renderer*const &ren, SDL_Window*const &window);
	void show(Uint16 *const &playerName, int score);

};

#endif // _GAMEOVER_H
