#pragma once

#include <SDL_ttf.h>
#include<iostream>
#include<string>
using namespace std;

class Menu {

private:
	SDL_Color color1 = { 250, 250, 250 };
	SDL_Color color2 = { 0, 250, 0 };
	TTF_Font* gFont = NULL;

public:
	void renderText(const char* text, int x, int y, SDL_Renderer* r, SDL_Color);
	void init();
	void render(SDL_Renderer* r);
	bool isMouseInsideRect(int mouseX, int mouseY, const SDL_Rect& rect);
};
