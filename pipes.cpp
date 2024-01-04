
#include"pipes.h"
#include<iostream>
using namespace std;


void obstacle::moveX() {

	SDL_Rect *r = getDest();
	r->x -= 2;

}

void obstacle::setPoz(bool t) {

	up = t;
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

	SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
	SDL_Rect obstacleRect;
	if (up == 1)
		obstacleRect = {getX(), getY(), getWidth(), getHeight() }; else 
		obstacleRect = {getX(),getY(), getWidth(), -getHeight() };
	SDL_RenderFillRect(r, &obstacleRect);

}

bool obstacle::getUp() {

	return up;
}




