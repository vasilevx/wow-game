#include "pause.h"

void pause::item(){
	SDL_Rect r = dest;
    text = TTF_RenderUTF8_Solid(textFont, "ПРОДОЛЖИТЬ", (menuSwitch == 0)? curTextColor : textColor);
    r.x = (dest.w - text->w) / 2; 
	r.y = dest.h * 4 / 9;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

    text = TTF_RenderUTF8_Solid(textFont, "ЗАВЕРШИТЬ", (menuSwitch == 1)? curTextColor : textColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h * 5 / 9;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);
}

pause::pause(SDL_Renderer*const &ren, SDL_Window*const &window) : UI(ren, window){
	SDL_Rect r = dest;
    text = TTF_RenderUTF8_Solid(bigFont, "ПАУЗА", titleColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h / 6;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

    item();

	text = TTF_RenderUTF8_Solid(smallFont, "Передвигайтесь с помощью стрелок, стреляйте пробелом", textColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h - text->h;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);
}

void pause::show() {
	if (texture)
		SDL_DestroyTexture(texture);
	texture = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_RenderCopy(ren, texture, NULL, &dest);

}

int pause::KeyEvent (SDL_KeyboardEvent & event){
    if(event.type==SDL_KEYDOWN){
        if(event.keysym.sym == SDLK_DOWN){
            if(menuSwitch != 1)
                ++menuSwitch;
            else
                menuSwitch = 0;
            item();
        }
        if(event.keysym.sym == SDLK_UP){
            if(menuSwitch != 0)
                --menuSwitch;
            else
                menuSwitch = 1;
            item();
        }
        if(event.keysym.sym==SDLK_RETURN){
            return menuSwitch;
        }
        if(event.keysym.sym==SDLK_ESCAPE){
            return menuSwitch=0;
        }
    }
    return -1;
}

int pause::MouseMotionEvent (SDL_MouseMotionEvent & motion){
    if(motion.type == SDL_MOUSEMOTION){
        if(motion.y >= dest.h * 4 / 9 && motion.y <= dest.h * 5 / 9){
            menuSwitch = 0;
            item();
        }
        if(motion.y >= dest.h * 5 / 9 && motion.y <= dest.h * 2 / 3){
            menuSwitch = 1;
            item();
        }
    }
    return -1;
}

int pause::MouseButtonEvent( SDL_MouseButtonEvent & button){
    if(button.type == SDL_MOUSEBUTTONDOWN){
        return menuSwitch;
    }
    return -1;
}
