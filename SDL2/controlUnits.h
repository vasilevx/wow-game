#ifndef _CONTROLUNITS_H
#define _CONTROLUNITS_H

#include "events.h"
#include "movingSurface.h"

//управляемые элементы
class controlUnits : public movingSurface, public events{
protected:
    char keyControl;
public:
    controlUnits();
    void show(); //отображение
	//virtual void ResetPos() = 0; //сброс параметров
	void move(char flag); //перемещение
	int KeyEvent (SDL_KeyboardEvent & event); //нажатие клавиши

};

#endif // _CONTROLUNITS_H
