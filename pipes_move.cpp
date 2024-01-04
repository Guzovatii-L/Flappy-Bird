
#include "pipes_move.h"

void obstacle2::moveY(int add) {

	SDL_Rect* r = getDest();
	r->h += add;
}

void obstacle2::setType() {

	type = true;
}

bool obstacle2::getType() {

	return type;
}

