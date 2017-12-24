#include "oneBigGame.h"


void closeSDL(SDL_Window* window, SDL_Renderer* ren) {
	endAudio();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(ren);
    TTF_Quit();
    SDL_Quit();
}

int main(int argc, char *argv[]){
	if (SDL_Init(SDL_INIT_EVERYTHING))
		return 1;
	if (TTF_Init())
		return 2;
	if (!IMG_Init(IMG_INIT_PNG))
		return 1;
	initAudio();

	SDL_Window* window = SDL_CreateWindow("Падение Легиона", 100, 100, W_WIDTH, W_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC || SDL_RENDERER_ACCELERATED);

    if(!(window && ren))
        return 3;
   	SDL_SetWindowIcon(window, SDL_LoadBMP("icon.bmp"));
	
    oneBigGame myGame(ren, window);
    myGame.start(ren);
	closeSDL(window, ren);
	return 0;
}
