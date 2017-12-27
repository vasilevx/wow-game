#include "oneBigGame.h"

oneBigGame::oneBigGame(SDL_Renderer *const &ren, SDL_Window *const &window) : playerName(), status(IntroStatus), background(ren, window),
intro(ren, window), menubg(ren, window), mainmenu(ren, window), gameplay(ren), gameover(ren, window), pausemenu(ren, window), username(ren, window, playerName),
record(ren, window), rule(ren, window), isDone(false) { }

void oneBigGame::start(SDL_Renderer*const &ren){
    SDL_Event event;
    int tmpItem = 0;
    while(!isDone){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                isDone = true;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if(status == MenuStatus)
                {
                    mainmenu.MouseMotionEvent(event.motion);
                }

                if(status == PauseStatus)
                {
                    pausemenu.MouseMotionEvent(event.motion);
                }

                if(status == RecordStatus)
                {
                    record.MouseMotionEvent(event.motion);
                }

				if (status == GameStatus && !gameplay.mouseControl) {
					gameplay.MouseMotionEvent(event.motion);
				}
            }

            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(status == IntroStatus)
                {
                    status = Status(NameStatus);
                } else

                if(status == MenuStatus)
                {
                    tmpItem = mainmenu.MouseButtonEvent(event.button);
                    if(tmpItem >=0)
                    {
                        if(tmpItem == 4)
                        {
                            isDone = true;
                        } else status = Status(tmpItem);
                    }
                } else

				if (status == GameStatus) {
					gameplay.MouseButtonEvent(event.button);
				} else
					

                if(status == PauseStatus)
                {
                    tmpItem = pausemenu.MouseButtonEvent(event.button);
                    if(tmpItem == 1)
                    {
                        gameplay.Reset();
                        status = Status(MenuStatus);
                    } else if(tmpItem == 0)
                    {
                        status = Status(GameStatus);
                    }
                } else

                if(status == GameOverStatus)
                {
                    gameplay.Reset();
                    status = Status(MenuStatus);
                } else

                if(status == RecordStatus)
                {
                    if(record.MouseButtonEvent(event.button) == 3) status = Status(MenuStatus);
                } else

                if(status == RuleStatus)
                {
                    if(rule.MouseButtonEvent(event.button) == 0) status = Status(MenuStatus);
                }
            }

            if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP || event.type == SDL_TEXTINPUT)
            {
                if(status == IntroStatus)
                {
                    status = Status(NameStatus);
                } else

                if(status == NameStatus)
                {
  					if (event.type == SDL_TEXTINPUT) {
						username.KeyEvent(event);
					} else {
						if (username.KeyEvent(event)) {
							status = Status(MenuStatus);
							
						}
					}
                } else

                if(status == MenuStatus)
                {
                    tmpItem = mainmenu.KeyEvent(event.key);
                    if(tmpItem >=0)
                    {
                        if(tmpItem == 4)
                        {
                            isDone = true;
                        } else status = Status(tmpItem);
                    }
                } else

                if(status == GameStatus)
                {
                    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
                        status = Status(PauseStatus);
                    else{
			            gameplay.KeyEvent(event.key);
                        gameplay.shoot(event.key);
                    }
                } else

                if(status == PauseStatus)
                {
                    tmpItem = pausemenu.KeyEvent(event.key);
                    if(tmpItem == 1)
                    {
                        gameplay.Reset();
                        status = Status(MenuStatus);
                    } else if(tmpItem == 0)
                    {
                        status = Status(GameStatus);
                    }
                } else

                if(status == GameOverStatus && event.key.keysym.sym == SDLK_RETURN)
                {
                    gameplay.Reset();
                    status = Status(MenuStatus);
                } else

                if(status == RecordStatus)
                {
                    if(record.KeyEvent(event.key) == 2) status = Status(MenuStatus);
                }else

                if(status == RuleStatus)
                {
                    if(rule.KeyEvent(event.key) == 0) status = Status(MenuStatus);
                }
            }


        }

        background.show();

        if(status == IntroStatus)
        {
            menubg.show();
            intro.show();

        } else

        if(status == NameStatus)
        {
            menubg.show();
            username.show();
        } else

         if(status == MenuStatus)
         {
             menubg.show();
             mainmenu.show(playerName);
         } else

        if(status == GameStatus)
        {
            gameplay.show();
            if(gameplay.Update() == false)
            {
                record.AddRecord(gameplay.GetScore(), playerName);
                status = Status(GameOverStatus);
            }
        } else

        if(status == PauseStatus)
        {
			menubg.show();
            pausemenu.show();
        } else

        if(status == GameOverStatus)
        {
            gameover.show(playerName, gameplay.GetScore());
        } else

        if(status == RecordStatus)
        {
            menubg.show();
            record.show();
        } else

        if(status == RuleStatus)
        {
            menubg.show();
            rule.show();
        }

		if (status == GameStatus && gameplay.mouseControl) {
			gameplay.MouseMotionEvent(event.motion);
		}
		SDL_RenderPresent(ren);
    }
}
