#include"Texture.h"

SDL_Texture* Texture::LoadTexture(const char* file, SDL_Renderer* r) {

	SDL_Surface* surface = IMG_Load(file);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(r, surface);

	SDL_FreeSurface(surface);
	return texture;
}