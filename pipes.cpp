
#include"pipes.h"
#include<iostream>
using namespace std;


void obstacle::moveX() {

	SDL_Rect *r = getDest();
	r->x -= 2;

}

void obstacle::setH() {

	SDL_Rect *r = getDest();
	r->h = rand() % 300 + 5;
}

void obstacle::setH2(int h) {

	SDL_Rect *r = getDest();
	r->h = rand() % (600 - h  - 200) + 5;
}

int obstacle::getX() {
	return (getDest()->x);
}
int  obstacle::getY() {

	return (getDest()->y);
}
int obstacle::getWidth() {

	return (getDest()->w);
}
int obstacle::getHeight() {
	return (getDest()->h);
}

void obstacle::render(SDL_Renderer* r) {

}


