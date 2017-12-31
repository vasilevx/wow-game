#ifndef _CONTROLUNITS_H
#define _CONTROLUNITS_H

#include "events.h"
#include "movingSurface.h"

//����������� ��������
class controlUnits : public movingSurface, public events{
protected:
    char keyControl;
public:
    controlUnits();
    void show(); //�����������
	void move(char flag); //�����������
	int KeyEvent (SDL_KeyboardEvent & event); //������� �������
	int MouseMotionEvent(SDL_MouseMotionEvent & motion, int x);
	int MouseButtonEvent(SDL_MouseButtonEvent & button);
	int mouseControl;

};

#endif // _CONTROLUNITS_H
