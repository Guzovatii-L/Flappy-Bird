#include"object.h"


object::object() {
	tex = NULL;
	dest.h = NULL;
	dest.w = NULL;
	src.h = NULL;
	src.w = NULL;
}

SDL_Texture* object::getTexture() {

	return tex;
}

SDL_Rect object::getSrc() {

	return src;
}

SDL_Rect* object::getDest() {

	return &dest;
}

void object::setS(int x, int y, int h, int w) {
	src.x = x;
	src.y = y;
	src.h = h;
	src.w = w;
}

void object::setD(int x, int y, int h, int w) {

	dest.x = x;
	dest.y = y;
	dest.h = h;
	dest.w = w;
}

void object::CreateTexture(const char* file, SDL_Renderer* r) {

	tex = Texture::LoadTexture(file, r);

}
