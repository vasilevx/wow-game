#ifndef _JUSTSDL_H_
#define _JUSTSDL_H_

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <cmath>
#include <stdio.h>
#include <string.h>
#include "globals.h"

#include "audio.h"
//все видимые элементы
class justSDL{
protected:
    SDL_Rect dest;
	SDL_Texture* texture;
	SDL_Renderer* ren;
public:
    SDL_Rect getCoords();
    justSDL();
    virtual void show() = 0;
    ~justSDL();
};


#endif
