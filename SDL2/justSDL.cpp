#include "justSDL.h"


justSDL::justSDL() : texture(NULL){
    dest.x = 0; 
	dest.y = 0;

    dest.w = 0; 
	dest.h = 0;
}

SDL_Rect justSDL::getCoords(){
    return dest;
}

justSDL::~justSDL(){
	if (texture)
		SDL_DestroyTexture(texture);
}
