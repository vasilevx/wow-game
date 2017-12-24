#ifndef _NOCONTROL_H
#define _NOCONTROL_H

#include "movingSurface.h"
class noControl : public movingSurface{
protected:
    double v;
public:
	explicit noControl() { };
	void show() { /* ����������� */
		SDL_RenderCopy(ren, texture, NULL, &dest);
	}
	void move(char flag); /* ����������� */

	virtual int GetScore() = 0; /* ��������� ����� */


};

#endif // _NOCONTROL_H
