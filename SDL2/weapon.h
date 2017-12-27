#ifndef _WEAPON_H
#define _WEAPON_H

#include "controlUnits.h"
class weapon : public controlUnits{
private:
    int shooted = 0;
    void setShoot(int a);
public:
    weapon(SDL_Renderer *const &ren);
    int isShooted();
    void getShoot(int a);
    void Reset(SDL_Renderer *const &ren, SDL_Rect cords);
    void move(char flag);
	//void show();
};

#endif // _WEAPON_H
