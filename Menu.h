#pragma once

#include <SDL_ttf.h>
#include<iostream>
#include<string>
using namespace std;

class Menu {

private:
	SDL_Color textColor = { 255, 255, 255 };
	TTF_Font* gFont = NULL;

public:
	void renderText(const char* text, int x, int y, SDL_Renderer* r);
	void init();
	void render(SDL_Renderer* r);
	bool isMouseInsideRect(int mouseX, int mouseY, const SDL_Rect& rect);
};
