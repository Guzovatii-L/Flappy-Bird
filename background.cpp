#include"background.h"

Background::Background() {
	setD(-5, 0, 620, 820);
}

void Background :: render(SDL_Renderer* r) {
	SDL_Rect *d = getDest();
	SDL_RenderCopy(r, getTexture(), NULL, d);
}