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

//состояние игры
class oneBigGame{
public:
    enum Status{
        GameStatus, //процесс игры
        NameStatus, //ввод имени
        RecordStatus, //рекорды
        RuleStatus, //правила
        PauseStatus, //пауза
        MenuStatus, //главное меню
        IntroStatus, //заставка
        GameOverStatus //конец игры
    };

private:
    Uint16 playerName[15]; //имя игрока
    Status status; //текущее состояние игры
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
