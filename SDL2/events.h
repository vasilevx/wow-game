#ifndef _EVENTS_H
#define _EVENTS_H

struct SDL_KeyboardEvent;
struct SDL_MouseMotionEvent;
struct SDL_MouseButtonEvent;
//�������
class events {
public:
    virtual int KeyEvent (SDL_KeyboardEvent & event) {return 5;} //����������
    virtual int MouseMotionEvent (SDL_MouseMotionEvent & montion) {return 5;} //�������� ����
    virtual int MouseButtonEvent (SDL_MouseButtonEvent & button) {return 5;} //������� ����
};

#endif // EVENTS_H
