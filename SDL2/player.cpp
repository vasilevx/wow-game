#include "player.h"

player::player(SDL_Renderer*const &ren) {
	this->ren = ren;

	SDL_Surface* pl = IMG_Load("illidan2.png");

	dest.w = pl->w;
	dest.h = pl->h;

	texture = SDL_CreateTextureFromSurface(ren, pl);
	SDL_FreeSurface(pl);

	dest.x = (W_WIDTH - dest.w)/2;
	dest.y = W_HEIGHT - dest.h;
}


void player::Reset(){
	dest.x = (W_WIDTH - dest.w) / 2;
	keyControl = 0;
}

