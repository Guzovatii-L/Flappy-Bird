#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include <stdexcept>
#include<iostream>
using namespace std;

class Texture {

public:
	static SDL_Texture* LoadTexture(const char* file, SDL_Renderer *r);
};
