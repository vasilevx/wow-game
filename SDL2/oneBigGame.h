#ifndef _ONEBIGGAME_H
#define _ONEBIGGAME_H

#include "background.h"
#include "menuBG.h"
#include "intro.h"
#include "username.h"
#include "mainMenu.h"
#include "gameplay.h"
#include "pause.h"
#include "gameOver.h"
#include "records.h"
#include "rules.h"
#include "globals.h"

//��������� ����
class oneBigGame{
public:
    enum Status{
        GameStatus, //������� ����
        NameStatus, //���� �����
        RecordStatus, //�������
        RuleStatus, //�������
        PauseStatus, //�����
        MenuStatus, //������� ����
        IntroStatus, //��������
        GameOverStatus //����� ����
    };

private:
    Uint16 playerName[15]; //��� ������
    Status status; //������� ��������� ����
    background background;
    intro intro;
    menuBG menubg;
    mainMenu mainmenu;
    gameplay gameplay;
    gameOver gameover;
    pause pausemenu;
    username username;
    records record;
    rules rule;
    bool isDone;

public:
    explicit oneBigGame(SDL_Renderer *const &ren, SDL_Window *const &window);
    void start(SDL_Renderer *const &ren);

};

#endif // _ONEBIGGAME_H
