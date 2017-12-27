#include "weapon.h"

weapon::weapon(SDL_Renderer *const &ren) {
	shooted = 0;
	this->ren = ren;

	SDL_Surface* pl = IMG_Load("weapon2.png");

	dest.w = pl->w;
	dest.h = pl->h;

	texture = SDL_CreateTextureFromSurface(ren, pl);
	SDL_FreeSurface(pl);

	dest.x = (W_WIDTH - dest.w) / 2;
	dest.y = W_HEIGHT - dest.h;
}
void weapon::Reset(SDL_Renderer *const &ren, SDL_Rect cords) {
    shooted = 0;
	dest.y = cords.y;
	dest.x = cords.x;
	}

void weapon::move(char flag) {
    if(shooted)
        controlUnits::move('f');
    else {
        controlUnits::move(flag);
    }
}

int weapon::isShooted(){
    return shooted;
}
void weapon::setShoot(int a){
    shooted = a;
}

void weapon::getShoot(int a){
    setShoot(a);
}

//void weapon::show() {
//	SDL_RenderCopy(ren, texture, NULL, &dest);
//}

