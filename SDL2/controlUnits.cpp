#include "controlUnits.h"

controlUnits::controlUnits() : keyControl(0) {}

void controlUnits::show(){
    move(keyControl);
    //контроль выхода за границы окна
    if(dest.x > (W_WIDTH - dest.w)) 
		dest.x = (W_WIDTH - dest.w);
    else if(dest.x < 0) dest.x = 0;
	SDL_RenderCopy(ren, texture, NULL, &dest);

}



void controlUnits::move(char flag){
    if(flag=='r')
        dest.x += 5;
    if(flag=='l')
        dest.x -= 5;
    if(flag=='f')
        dest.y -= 20;
}

int controlUnits::KeyEvent (SDL_KeyboardEvent & event){
    if(event.type==SDL_KEYDOWN || event.type == SDL_TEXTINPUT) {
        if(event.keysym.sym==SDLK_LEFT){
            keyControl = 'l';
        }
        if(event.keysym.sym==SDLK_RIGHT){
            keyControl = 'r';
        }
        if(event.keysym.sym==SDLK_SPACE){
            keyControl = 'f';
        }
        return 1;
    }
    else if(event.type == SDL_KEYUP){
        if(event.keysym.sym==SDLK_LEFT || event.keysym.sym==SDLK_RIGHT){
            keyControl = 0;
        }
    }
    return 0;
}
