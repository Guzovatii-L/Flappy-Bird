#pragma once
#include"Font.h"
#include<string>
using namespace std;

class Menu : public Font{

private:
	SDL_Color color1;
	SDL_Color color2;
public:
	Menu();
	void renderText(const char* text, int x, int y, SDL_Renderer* r, SDL_Color);
	void render(SDL_Renderer* r);
	bool isMouseInsideRect(int mouseX, int mouseY, const SDL_Rect& rect);
};
