#pragma once
#include"Texture.h"

class object {
private:

	SDL_Rect src, dest;
	SDL_Texture* tex;

public:

	object();
	void setS(int x, int y, int h, int w);
	void setD(int x, int y, int h, int w);
	SDL_Texture* getTexture();
	SDL_Rect getSrc();
	SDL_Rect* getDest();
	void CreateTexture(const char* file, SDL_Renderer* r);
	void virtual render(SDL_Renderer* ren) = 0;

};
