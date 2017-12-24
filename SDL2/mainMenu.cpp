#include "mainMenu.h"

void mainMenu::items(){
	SDL_Rect r = dest;
	text = TTF_RenderUTF8_Solid(textFont, "ИГРАТЬ", (menuSwitch == 0)? curTextColor : textColor);
    r.x = (dest.w - text->w) / 2; 
	r.y = dest.h * 3 / 9;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

	text = TTF_RenderUTF8_Solid(textFont, "СМЕНА ИГРОКА", (menuSwitch == 1)? curTextColor : textColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h * 4 / 9;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

	text = TTF_RenderUTF8_Solid(textFont, "РЕКОРДЫ", (menuSwitch == 2)? curTextColor : textColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h * 5 / 9;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

	text = TTF_RenderUTF8_Solid(textFont, "ПРАВИЛА", (menuSwitch == 3)? curTextColor : textColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h * 2 / 3;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

	text = TTF_RenderUTF8_Solid(textFont, "ВЫХОД", (menuSwitch == 4)? curTextColor : textColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h * 7 / 9;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);
}

mainMenu::mainMenu(SDL_Renderer*const &ren, SDL_Window *const &window) : UI(ren, window){
	SDL_Rect r = dest;
	
	text = TTF_RenderUTF8_Solid(bigFont, "МЕНЮ", titleColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h * 1.5 / 9;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);
    items();
}

void mainMenu::show(Uint16 *const &playerName){
	SDL_Rect r = dest;
    if(playerName[0] != 0){
        text = TTF_RenderUNICODE_Solid(textFont, playerName, textColor);
        r.x = (dest.w - text->w)/2; 
		r.y = text->h;
		r.w = text->w;
		r.h = text->h;
		
		SDL_Texture *tText = SDL_CreateTextureFromSurface(ren, text);
		SDL_FreeSurface(text);
		SDL_RenderCopy(ren, tText, nullptr, &r);
		SDL_DestroyTexture(tText);
	}
	// Наложение поверхности - фон на экран
	if (texture) SDL_DestroyTexture(texture);
	texture = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_RenderCopy(ren, texture, nullptr, &dest);
}

int mainMenu::KeyEvent (SDL_KeyboardEvent & event){
    if(event.type == SDL_KEYDOWN){
        if(event.keysym.sym == SDLK_DOWN){
            if(menuSwitch != 4)
                ++menuSwitch;
            else
                menuSwitch = 0;
            items();
        }
        if(event.keysym.sym == SDLK_UP){
            if(menuSwitch != 0)
                --menuSwitch;
            else
                menuSwitch = 4;
            items();
        }
        if(event.keysym.sym == SDLK_RETURN){
            return menuSwitch;
        }
    }
    return -1;
}

int mainMenu::MouseMotionEvent (SDL_MouseMotionEvent & motion){
    if(motion.type == SDL_MOUSEMOTION){
        if(motion.y >= dest.h / 3 && motion.y <= dest.h * 4 / 9){
            menuSwitch = 0;
            items();
        }
        if(motion.y >= dest.h * 4 / 9 && motion.y <= dest.h * 5 / 9){
            menuSwitch = 1;
            items();
        }
        if(motion.y >= dest.h * 5 / 9 && motion.y <= dest.h * 2 /3){
            menuSwitch = 2;
            items();
        }
        if(motion.y >= dest.h * 2 / 3 && motion.y <= dest.h * 7 / 9){
            menuSwitch = 3;
            items();
        }
        if(motion.y >= dest.h * 7 / 9 && motion.y <= dest.h * 8 / 9){
            menuSwitch = 4;
            items();
        }
    }
    return -1;
}

int mainMenu::MouseButtonEvent( SDL_MouseButtonEvent & button){
    if(button.type == SDL_MOUSEBUTTONDOWN){
        return menuSwitch;
    }
    return -1;
}
