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
	//virtual void ResetPos() = 0; //����� ����������
	void move(char flag); //�����������
	int KeyEvent (SDL_KeyboardEvent & event); //������� �������

};

#endif // _CONTROLUNITS_H
