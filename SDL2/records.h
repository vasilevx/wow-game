#ifndef _RECORDS_H
#define _RECORDS_H

#include "UI.h"
#include <fstream>
//рекорды
struct userRecord{
    Uint16 name[15];
    int score;
    userRecord() : name(), score(0) { }//сброс
    userRecord & operator = (const userRecord &record){ //присваивание
        this->score = record.score;
        memcpy(this->name, record.name, 15*sizeof(Uint16));
        return *this;
    }
};

class records : public UI
{
protected:
    int count;
    struct userRecord mas[10];
    void Item();

public:
    explicit records(SDL_Renderer*const &ren, SDL_Window*const &window);
    void show();
    int KeyEvent (SDL_KeyboardEvent & event);
    int MouseMotionEvent (SDL_MouseMotionEvent & motion);
    int MouseButtonEvent( SDL_MouseButtonEvent & button);
    void Clear();
    void Print();
    void AddRecord(int score, Uint16 *const &playerName);
    void ConvertUTF16toUTF8 (const Uint16 * sourceStart, const int sourceCount,
    Uint8 * targetStart, const int targetCount);
    ~records();
};

#endif // _RECORDS_H
