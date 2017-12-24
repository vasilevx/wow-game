#ifndef _MOVINGSURFACE_H_
#define _MOVINGSURFACE_H_

#include "justSDL.h"
#include "moving.h"

//поверхность перемещ€емых элементов
class movingSurface : public justSDL, public moving{
public:
	virtual void show() = 0;
	virtual void move(char flag) = 0;

    int GetX(){
        return dest.x;
    }
    int GetY(){
        return dest.y;
    }
	int GetH() { 
		 return dest.h;
	 }
	int GetW() {
		 return dest.w;
	 }
};

#endif


