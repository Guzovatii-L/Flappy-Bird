
#include"background.h"

void background :: render(SDL_Renderer* r) {

	//SDL_Rect s = getSrc();
	//SDL_Rect d = getDest();
	SDL_RenderCopy(r, getTexture(), NULL, NULL);
}