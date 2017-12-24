#include "records.h"

void records::Item(){
	SDL_Rect r = dest;
    text = TTF_RenderUTF8_Solid(textFont, "УДАЛИТЬ ВСЕ", (menuSwitch == 0)? curTextColor : textColor);
    r.x = (dest.w - text->w) / 2; 
	r.y = dest.h * 13 / 18;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

    text = TTF_RenderUTF8_Solid(textFont, "ПЕЧАТЬ В ФАЙЛ", (menuSwitch == 1)? curTextColor : textColor);
    r.x = (dest.w - text->w) / 2; 
	r.y += dest.h / 9;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);


}

records::records(SDL_Renderer*const &ren, SDL_Window*const &window) : UI(ren,window), count(0){
    std::ifstream file("records.dat");

    for(int i = 0; count < 10 && file.read(reinterpret_cast<char*>(&mas[i]), sizeof(struct userRecord)); ++i) ++count;
    file.close();

	SDL_Rect r = dest;
    text = TTF_RenderUTF8_Solid(bigFont, "РЕКОРДЫ", titleColor);
    r.x = (dest.w - text->w) / 2; 
	r.y = dest.h / 6;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);

    Item();


    text = TTF_RenderUTF8_Solid(smallFont, "Нажмите Esc для возврата в главное меню", textColor);
    r.x = (dest.w - text->w) / 2; 
	r.y = dest.h - text->h;
    SDL_BlitSurface(text, NULL, textSurface, &r);
    SDL_FreeSurface(text);
}

void records::show(){
	SDL_Rect r = dest;
	SDL_Rect rect;

	rect.w = 500;
	rect.h = 400;
	rect.x = (dest.w - 500) / 2;
	rect.y = 200;
	SDL_FillRect(textSurface, &rect, SDL_MapRGB(textSurface->format, 8, 68, 6));


	Item();

	TTF_Font * font  = TTF_OpenFont("OpenSans-Regular.ttf", dest.w * dest.h / 24000);
    char txtbuf[100];
    r.y = dest.h * 4.5 / 18;
    for(int i = 0; i < count; ++i){
        memset(txtbuf,0,100);
        sprintf_s(txtbuf,"%d ",i+1);

        text = TTF_RenderText_Solid(font, txtbuf, textColor);
        r.x = dest.w / 3 - text->w; 
		r.y += text->h;
        SDL_BlitSurface(text, NULL, textSurface, &r);
        SDL_FreeSurface(text);

		text = TTF_RenderUNICODE_Solid(font, mas[i].name, textColor);
        r.x = dest.w / 3;
		SDL_BlitSurface(text, NULL, textSurface, &r);
        SDL_FreeSurface(text);

        memset(txtbuf,0,100);
        sprintf_s(txtbuf,"%d",mas[i].score);
		text = TTF_RenderText_Solid(font, txtbuf, textColor);
        r.x = W_WIDTH * 2 / 3;
		SDL_BlitSurface(text, NULL, textSurface, &r);
        SDL_FreeSurface(text);
    }
	if (texture) SDL_DestroyTexture(texture);
	texture = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_RenderCopy(ren, texture, nullptr, &dest);

    TTF_CloseFont(font);
}

int records::KeyEvent (SDL_KeyboardEvent & event)
{
    if(event.type==SDL_KEYDOWN){
        if(event.keysym.sym == SDLK_DOWN){
            if(menuSwitch != 1)
                ++menuSwitch;
            else
                menuSwitch = 0;
            Item();
        }
        if(event.keysym.sym == SDLK_UP){
            if(menuSwitch != 0)
                --menuSwitch;
            else
                menuSwitch = 1;
            Item();
        }
        if(event.keysym.sym==SDLK_RETURN){
            if(menuSwitch)
                Print();
            else
                Clear();
            return menuSwitch;
        }
        if(event.keysym.sym==SDLK_ESCAPE){
            return 2;
        }
    }
    return -1;
}

int records::MouseMotionEvent (SDL_MouseMotionEvent & motion){
    if(motion.type == SDL_MOUSEMOTION){
        if(motion.y >= dest.h * 13 / 18 && motion.y <= dest.h * 15 / 18){
            menuSwitch = 0;
            Item();
        }
        if(motion.y >= dest.h * 15 / 18 && motion.y <= dest.h * 17 / 18){
            menuSwitch = 1;
            Item();
        }
        if(motion.y >= 0 && motion.y <= dest.h / 9 && motion.x >= 0 && motion.y <= dest.w / 9){
            menuSwitch = 2;
            Item();
        }
    }
    return -1;
}

int records::MouseButtonEvent( SDL_MouseButtonEvent & button){
    if(button.type == SDL_MOUSEBUTTONDOWN){
        if(menuSwitch == 1)
            Print();
        else if(menuSwitch == 0)
            Clear();
        return menuSwitch;
    }
    return -1;
}

void records::Clear(){
    count = 0;

}

void records::Print(){
    std::ofstream file("records.txt");
    Uint8 str[30];
    for(int i = 0; i < count; ++i){
        ConvertUTF16toUTF8(&mas[i].name[0], 15, str, 30);
        file << i + 1 << ". " << str << "\t" << mas[i].score << std::endl;
    }
    file.close();
}

void records::AddRecord(int score, Uint16 *const &playerName){
    int i = 0;
    while(score < mas[i].score && i < count) i++;
    if(count < 10) ++count;
    for(int k = count-1; k > i; --k){
        mas[k] = mas[k-1];
    }
    mas[i].score = score;
    memcpy(mas[i].name, playerName, 15*sizeof(Uint16));
}

void records::ConvertUTF16toUTF8 (const Uint16 * sourceStart, const int sourceCount,
Uint8 * targetStart, const int targetCount){//перевод кодировки
     /* Once the bits are split out into bytes of UTF-8, this is a mask OR-ed
     * into the first byte, depending on how many bytes follow.  There are
     * as many entries in this table as there are UTF-8 sequence types.
     * (I.e., one byte sequence, two byte... etc.). Remember that sequencs
     * for *legal* UTF-8 will be 4 or fewer bytes total. */
    static const Uint8 firstByteMark[7] = { 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC };
    static const int halfShift  = 10; /* Используется для смещения на 10 бит */
    static const Uint32 halfBase = 0x0010000UL;
    static const Uint32 halfMask = 0x3FFUL;
    static const Uint32 byteMask = 0xBF;
    static const Uint32 byteMark = 0x80;


    Uint8 * targetEnd = targetStart + targetCount;
    const Uint16* sourceEnd = sourceStart + sourceCount;


    const Uint16* source = sourceStart;
    Uint8* target = targetStart;

    while (source < sourceEnd){
        Uint32 ch;
        unsigned short bytesToWrite = 0;

        const Uint16* oldSource = source;
        ch = *source++;


        if (ch >= 0xD800u && ch <= 0xDBFFu){
            /* If the 16 bits following the high surrogate are in the source buffer... */
            if (source < sourceEnd){
                Uint32 ch2 = *source;
                /* If it's a low surrogate, convert to UTF32. */
                if (ch2 >= 0xDC00u && ch2 <= 0xDFFFu){
                    ch = ((ch - 0xD800u) << halfShift) + (ch2 - 0xDC00u) + halfBase;
                    ++source;
                }
            } else{ /* We don't have the 16 bits following the high surrogate. */
                --source; /* return to the high surrogate */
                break;
            }
        }

        /* Figure out how many bytes the result will require */
        if (ch < 0x80u)
        {
            bytesToWrite = 1;
        } else
        if (ch < 0x800u)
        {
            bytesToWrite = 2;
        } else
        if (ch < 0x10000u)
        {
            bytesToWrite = 3;
        } else
        if (ch < 0x110000u)
        {
            bytesToWrite = 4;
        } else
        {
            bytesToWrite = 3;
            ch = 0x0000FFFDu;
        }

        target += bytesToWrite;
        if (target > targetEnd){
            source = oldSource;
            target -= bytesToWrite;
            break;
        }

        switch (bytesToWrite)
        { /* note: everything falls through. */
            case 4: *--target = (Uint8)((ch | byteMark) & byteMask); ch >>= 6;
            case 3: *--target = (Uint8)((ch | byteMark) & byteMask); ch >>= 6;
            case 2: *--target = (Uint8)((ch | byteMark) & byteMask); ch >>= 6;
            case 1: *--target =  (Uint8)(ch | firstByteMark[bytesToWrite]);
        }
        target += bytesToWrite;
    }
}

records::~records(){
    std::ofstream file("records.dat");
    file.write(reinterpret_cast<char*>(mas), sizeof(userRecord) * count);
    file.close();
}
