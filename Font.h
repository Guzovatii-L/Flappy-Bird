#pragma once
#include <SDL_ttf.h>
#include<iostream>
using namespace std;

class Font {
private:
	TTF_Font* gFont;
public:
	Font();
	~Font();
	TTF_Font* getFont();
};