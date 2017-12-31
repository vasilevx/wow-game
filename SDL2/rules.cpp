#include "rules.h"

rules::rules(SDL_Renderer*const &ren, SDL_Window*const &window) : UI(ren, window){

	SDL_Rect r = dest;

    text = TTF_RenderUTF8_Solid(bigFont, "ПРАВИЛА", titleColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h * 3 / 18;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

    TTF_Font * font = TTF_OpenFont("OpenSans-Regular.ttf", dest.w  *dest.h / 20000);
    text = TTF_RenderUTF8_Solid(font, "Метайте в демонов клинок.", textColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h / 3;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

	text = TTF_RenderUTF8_Solid(font, "За каждого демона дают очки:", textColor);
    r.x = (dest.w - text->w) / 2;
	r.y += dest.h / 18;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

	text = TTF_RenderUTF8_Solid(font, "3 - за питлорда, 2 - за мать бесов", textColor);
    r.x = (dest.w - text->w) / 2;
	r.y += dest.h / 18;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

	text = TTF_RenderUTF8_Solid(font, "и 1 - за мелкого беса.", textColor);
    r.x = (dest.w - text->w) / 2;
	r.y += dest.h / 18;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

	text = TTF_RenderUTF8_Solid(font, "При поражении 10 демонов", textColor);
    r.x = (dest.w - text->w) / 2;
	r.y += dest.h / 9;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

	text = TTF_RenderUTF8_Solid(font, "повышается уровень сложности.", textColor);
    r.x = (dest.w - text->w) / 2;
	r.y += dest.h / 18;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

    TTF_CloseFont(font);

	text = TTF_RenderUTF8_Solid(smallFont, "Нажмите Esc для возврата в главное меню", textColor);
    r.x = (dest.w - text->w) / 2;
	r.y = dest.h - text->h;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);
	


}

int rules::KeyEvent (SDL_KeyboardEvent & event){
    if(event.type==SDL_KEYDOWN){
        if(event.keysym.sym==SDLK_ESCAPE){
            return 0;
        }
    }
    return -1;
}

int rules::MouseButtonEvent( SDL_MouseButtonEvent & button){
    return -1;
}
