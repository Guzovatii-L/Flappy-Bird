#include "pipes_move.h"

void MovePipe::moveY(int add) {
	SDL_Rect* r = getDest();
	r->h += add;
}

void MovePipe::setType() {
	moveType = true;
}

bool MovePipe::getType() {
	return moveType;
}

