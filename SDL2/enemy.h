#ifndef _ENEMY_H
#define _ENEMY_H

#include "noControl.h"

enum demonType { /* Возможные типы демонов */
	demon1,
	demon2,
	demon3,
};
class enemy : public noControl {
public:
	demonType enemyShipType;
	explicit enemy(SDL_Renderer*const &ren, demonType type, int level);
	void SetStatus(SDL_Renderer*const &ren, demonType type, int level);
    int GetScore();
};

#endif // _ENEMY_H
