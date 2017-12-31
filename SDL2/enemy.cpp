#include "enemy.h"

enemy::enemy(SDL_Renderer*const &ren, demonType type, int level) : noControl(){
    SetStatus(ren, type, level);
}

void enemy::SetStatus(SDL_Renderer*const &ren, demonType type, int level){

	this->ren = ren;
    int leftOrRight = rand()%2;
    dest.y = rand() % (W_HEIGHT/2);
    if(leftOrRight == 1){
        v = 1;
        dest.x = 0;
    }
    else{
        v = -1;
        dest.x = W_WIDTH;
    }
    enemyShipType = type;
	v+=level*0.5;




    if(enemyShipType == demon3){
        v*=3;
		SDL_Surface* demon3 = IMG_Load("demon3small.png");
		dest.w = demon3->w;
		dest.h = demon3->h;
		texture = SDL_CreateTextureFromSurface(ren, demon3);
		SDL_FreeSurface(demon3);

		return;
    }
    else if(enemyShipType == demon1){
        v*=1;
		SDL_Surface* demon1 = IMG_Load("demon1small.png");
		dest.w = demon1->w;
		dest.h = demon1->h;
		texture = SDL_CreateTextureFromSurface(ren, demon1);
		SDL_FreeSurface(demon1); 


		return;
    }
    else if(enemyShipType == demon2){
        v*=2;
		SDL_Surface* demon2 = IMG_Load("demon2small.png");
		dest.w = demon2->w;
		dest.h = demon2->h;
		texture = SDL_CreateTextureFromSurface(ren, demon2);
		SDL_FreeSurface(demon2); 

		return;

    }


}

int enemy::GetScore(){
    if(enemyShipType == demon3){
        return 3;
    }
    else if(enemyShipType == demon2){
        return 2;
    }
    else if(enemyShipType == demon1){
        return 1;
    }
    return 0;
}
