#include "gameplay.h"

gameplay::gameplay(SDL_Renderer*const &ren) : myPlayer(ren), score(0), shootedGlaives(0), hits(0),curHits(0), totalGlaives(10), level(1), myWeapon(ren)
{
    int i;
	this->ren = ren;

    dest.y = 5;

    for(i=0; i<=1; ++i)
        enemyDemons.push_back(new enemy(ren, demonType(rand()%3), level));
}

void gameplay::show()
{
    SDL_Color color; color.r = 255, color.g = 255, color.b = 255;
    SDL_Rect r; r.y = 0;
    TTF_Font* font = TTF_OpenFont("OpenSans-Regular.ttf", W_WIDTH * W_HEIGHT / 11000);

    char txtbuf[100];
    memset(txtbuf,0,100);
    sprintf_s(txtbuf,"%d",score);
    SDL_Surface *text = TTF_RenderUTF8_Solid(font, txtbuf, color);
	r.x = W_WIDTH - text->w;
	r.w = text->w;
	r.h = text->h;
	SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(ren, text);
    SDL_FreeSurface(text);
	SDL_RenderCopy(ren, scoreTexture, NULL, &r);
	SDL_DestroyTexture(scoreTexture);

    color.r = 255, color.g = 0, color.b = 0;

    text = TTF_RenderUTF8_Solid(font, "К:", color);
	r.x = 5;
	r.w = text->w;
	r.h = text->h;
	scoreTexture = SDL_CreateTextureFromSurface(ren, text);
	SDL_FreeSurface(text);
	SDL_RenderCopy(ren, scoreTexture, NULL, &r);
	SDL_DestroyTexture(scoreTexture);

    char txtbuf2[100];
    memset(txtbuf2,0,100);
    sprintf_s(txtbuf2,"%d",totalGlaives);
	text = TTF_RenderUTF8_Solid(font, txtbuf2, color);
	r.x = 50;
	r.w = text->w;
	r.h = text->h;
	scoreTexture = SDL_CreateTextureFromSurface(ren, text);
	SDL_FreeSurface(text);
	SDL_RenderCopy(ren, scoreTexture, NULL, &r);
	SDL_DestroyTexture(scoreTexture);

    text = TTF_RenderUTF8_Solid(font, "П:", color);
	r.x = 140;
	r.w = text->w;
	r.h = text->h;
	scoreTexture = SDL_CreateTextureFromSurface(ren, text);
	SDL_FreeSurface(text);
	SDL_RenderCopy(ren, scoreTexture, NULL, &r);
	SDL_DestroyTexture(scoreTexture);

    char txtbuf3[100];
    memset(txtbuf3,0,100);
    sprintf_s(txtbuf3,"%d",curHits);
	text = TTF_RenderUTF8_Solid(font, txtbuf3, color);
	r.x = 200;
	r.w = text->w;
	r.h = text->h;
	scoreTexture = SDL_CreateTextureFromSurface(ren, text);
	SDL_FreeSurface(text);
	SDL_RenderCopy(ren, scoreTexture, NULL, &r);
	SDL_DestroyTexture(scoreTexture);

	text = TTF_RenderUTF8_Solid(font, "У:", color);
    r.x = 280;
	r.w = text->w;
	r.h = text->h;
	scoreTexture = SDL_CreateTextureFromSurface(ren, text);
	SDL_FreeSurface(text);
	SDL_RenderCopy(ren, scoreTexture, NULL, &r);
	SDL_DestroyTexture(scoreTexture);

    char txtbuf4[100];
    memset(txtbuf4,0,100);
    sprintf_s(txtbuf4,"%d",level);
	text = TTF_RenderUTF8_Solid(font, txtbuf4, color);
    r.x = 340;
	r.w = text->w;
	r.h = text->h;
	scoreTexture = SDL_CreateTextureFromSurface(ren, text);
	SDL_FreeSurface(text);
	SDL_RenderCopy(ren, scoreTexture, NULL, &r);
	SDL_DestroyTexture(scoreTexture);
    TTF_CloseFont(font);
	text = NULL;
   
    for(int i=0; i<=1; ++i)
        enemyDemons[i]->show();
	myWeapon.show();
    myPlayer.show();
}


bool gameplay::Update() //игра
{
    for(int i=0; i<=1; ++i)
    {

        if(myWeapon.GetX()!= myPlayer.GetX() && !myWeapon.isShooted()){
            myWeapon.Reset(ren, myPlayer.getCoords());

        }
        if(myWeapon.GetY()<=0){
            myWeapon.Reset(ren, myPlayer.getCoords());
            shootedGlaives++;
            totalGlaives--;
        }


		if ((myWeapon.GetY() != myPlayer.GetY()) && !(myWeapon.isShooted())) {
			myWeapon.Reset(ren, myPlayer.getCoords());
		}

        enemyDemons[i]->move('m');
        if(enemyDemons[i]->GetX() >= W_WIDTH || enemyDemons[i]->GetX() <= 0){
            enemyDemons[i]->SetStatus(ren, demonType(rand()%3),level);
        }

        if(myWeapon.GetX()+myWeapon.GetW()>=enemyDemons[i]->GetX() && myWeapon.GetX()<=enemyDemons[i]->GetX()+enemyDemons[i]->GetW() && myWeapon.isShooted()){//попадание по демону
            if(myWeapon.GetY()>=enemyDemons[i]->GetY() && myWeapon.GetY() <= enemyDemons[i]->GetY()+enemyDemons[i]->GetH()){
                if(enemyDemons[i]->GetScore()){
                    myWeapon.Reset(ren, myPlayer.getCoords());
                    score += enemyDemons[i]->GetScore();
                    hits++;
                    shootedGlaives++;
                    curHits++;
                    --totalGlaives;
                }
                enemyDemons[i]->SetStatus(ren, demonType(rand()%3),level);
            }
        }
        if(totalGlaives == 0 && curHits <10) return false;
        if(totalGlaives == 0 && curHits % 10==0 && hits==shootedGlaives){
            ++level;
            totalGlaives = 10;
            curHits = 0;
        }



		
    }



	SDL_Delay(1000/60);



    return true;
}

int gameplay::KeyEvent(SDL_KeyboardEvent & event){
	mouseControl = 0;
	if (event.keysym.sym != SDLK_SPACE) {
		return myPlayer.KeyEvent(event);
	}
	return 0;
}

int gameplay::MouseMotionEvent(SDL_MouseMotionEvent & motion) {
	mouseX = motion.x;
	mouseControl = 1;
	

		if (mouseX > (myPlayer.GetX() + myPlayer.GetW() / 2))
			myPlayer.move('r');
		if (mouseX < (myPlayer.GetX() + myPlayer.GetW() / 2))
			myPlayer.move('l');
		if (!myWeapon.isShooted()) {
			myWeapon.Reset(ren, myPlayer.getCoords());
		}
	

	return 0;
}
int gameplay::MouseButtonEvent(SDL_MouseButtonEvent & button) {
	if (myWeapon.isShooted()) return 0;
	if (button.type == SDL_MOUSEBUTTONDOWN && button.button == SDL_BUTTON_LEFT)
	{
		myWeapon.getShoot(1);
		button.type = NULL;
		return myWeapon.MouseButtonEvent(button);
	}
	return 0;
}





int gameplay::shoot(SDL_KeyboardEvent & event){
    if(myWeapon.isShooted()) return 0;
    if(event.keysym.sym==SDLK_SPACE && event.type==SDL_KEYDOWN){
        myWeapon.getShoot(1);
        event.keysym.sym=SDLK_BACKSLASH;
    }
    return myWeapon.KeyEvent(event);
}


void gameplay::Reset(){
    totalGlaives = 10;
    score = 0;
    curHits = 0;
    hits = 0;
    shootedGlaives = 0;
    level = 1;
    for(int i=0; i<=1; ++i)
        enemyDemons[i]->SetStatus(ren, demonType(rand()%3),level);
    myPlayer.Reset();//here
    myWeapon.Reset(ren, getCoords());
}
