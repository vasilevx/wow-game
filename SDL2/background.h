#ifndef _BACKGROUND_H
#define _BACKGROUND_H

#include "UI.h"
//��� ���� 
class background : public UI{
public:
	explicit background(SDL_Renderer*const &ren, SDL_Window*const &window);
};

#endif // _BACKGROUND_H
