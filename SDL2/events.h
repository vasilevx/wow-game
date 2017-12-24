#ifndef _EVENTS_H
#define _EVENTS_H

struct SDL_KeyboardEvent;
struct SDL_MouseMotionEvent;
struct SDL_MouseButtonEvent;
//события
class events {
public:
    virtual int KeyEvent (SDL_KeyboardEvent & event) {return 5;} //клавиатура
    virtual int MouseMotionEvent (SDL_MouseMotionEvent & montion) {return 5;} //движение мыши
    virtual int MouseButtonEvent (SDL_MouseButtonEvent & button) {return 5;} //нажатие мыши
};

#endif // EVENTS_H
