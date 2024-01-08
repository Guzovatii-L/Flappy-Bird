#pragma once
#include"Texture.h"
#include<fstream>
#include<iostream>
using namespace std;

class Object {
private:

	SDL_Rect dest;
	SDL_Texture* tex;

public:
	Object();
	~Object();
	void setD(int x, int y, int h, int w);
	SDL_Texture* getTexture();
	SDL_Rect* getDest();
	void CreateTexture(const char* file, SDL_Renderer* r);
	void virtual render(SDL_Renderer* ren) = 0;
};
