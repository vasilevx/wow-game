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
//������� �������
class gameplay : public justSDL, events{
private:
    std::vector<enemy*> enemyDemons; //������
    player myPlayer; //�������
    weapon myWeapon;
	int score; //����
	int totalGlaives; //���-�� �������
	int hits; //����� ���������
	int level; //�������
	int curHits; //��������� �� ������
	int shootedGlaives; //��������� �� �������
	int mouseX;//���������� �������


public:
	int mouseControl;
	explicit gameplay(SDL_Renderer*const &ren);
    void show();
    bool Update();
    int KeyEvent(SDL_KeyboardEvent & event);
	int MouseMotionEvent(SDL_MouseMotionEvent & motion);
	int MouseButtonEvent(SDL_MouseButtonEvent & button);
    int shoot(SDL_KeyboardEvent & event);
    void Reset();
    int GetScore()
    {
        return score;
    }

};

#endif // _GAMEPLAY_H
