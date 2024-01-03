#pragma once
#include<SDL.h>
#include<SDL_image.h>

class Texture {

public:

	static SDL_Texture* LoadTexture(const char* file, SDL_Renderer *r);

};
