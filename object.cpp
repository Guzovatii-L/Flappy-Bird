#include"object.h"

Object::Object() {
	tex = NULL;
	dest.h = NULL;
	dest.w = NULL;
}

Object::~Object() {
	if (tex != NULL) {
		delete tex;
		tex = NULL;
	}
}

SDL_Texture* Object::getTexture() {
	return tex;
}

SDL_Rect* Object::getDest() {
	return &dest;
}

void Object::setD(int x, int y, int h, int w) {
	dest.x = x;
	dest.y = y;
	dest.h = h;
	dest.w = w;
}

void Object::CreateTexture(const char* file, SDL_Renderer* r) {
	tex = Texture::LoadTexture(file, r);
}
