#pragma once

#include <SDL_ttf.h>
#include<iostream>
#include<string>
using namespace std;

class Score {

private:

	TTF_Font* gFont = NULL;
	int score = 0;

public:

	SDL_Texture* renderText(SDL_Renderer* r);
	void render(SDL_Renderer *r);
	void updateScore();
	void init();

};
