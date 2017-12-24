#ifndef _GAMEPLAY_H
#define _GAMEPLAY_H

#include "stdlib.h"
#include "time.h"
#include <vector>
#include "background.h"
#include "intro.h"
#include "menuBG.h"
#include "rules.h"
#include "mainMenu.h"
#include "pause.h"
#include "enemy.h"
#include "player.h"
#include "weapon.h"
//игровой процесс
class gameplay : public justSDL, events{
private:
    std::vector<enemy*> enemyDemons; //демоны
    player myPlayer; //иллидан
    weapon myWeapon;
	int score; //очки
	int totalGlaives; //кол-во клинков
	int hits; //всего попаданий
	int level; //уровень
	int curHits; //попадания на уровне
	int shootedGlaives; //попадания по демонам

public:
	explicit gameplay(SDL_Renderer*const &ren);
    void show();
    bool Update();
    int KeyEvent(SDL_KeyboardEvent & event);
    int shoot(SDL_KeyboardEvent & event);
    void Reset();
    int GetScore()
    {
        return score;
    }
	//~gameplay();
};

#endif // _GAMEPLAY_H
