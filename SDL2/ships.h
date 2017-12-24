#ifndef _SHIPS_H
#define _SHIPS_H

#include "noControl.h"
//�������
class ships : public noControl{
public:
    enum shipType{ /* ��������� ���� ������� */
        demon3,
        demon2,
        demon3,
    };
	ships(SDL_Renderer* ren, int level);
    virtual void SetStatus(SDL_Renderer* ren, shipType type, int level) = 0;
	~ships();
};

#endif // _SHIPS_H
