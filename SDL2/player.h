#ifndef _PLAYER_H
#define _PLAYER_H

#include "controlUnits.h"
//��������, ����������� �������
class player : public controlUnits{
public:
      player(SDL_Renderer*const &ren);
	  //void show();
	 // void move(char flag);
	  void Reset();


};

#endif // _PLAYER_H
