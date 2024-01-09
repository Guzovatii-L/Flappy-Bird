#pragma once


#include"Font.h"
#include<string>
#include<fstream>
using namespace std;

class Score : public Font{
private:
	int score;
	int scoreTimer;
public:
	Score();
	~Score();
	SDL_Texture* renderText(SDL_Renderer* r);
	void write();
	void read();
	void render(SDL_Renderer *r);
	void updateScore();
	void resetScore();
};
