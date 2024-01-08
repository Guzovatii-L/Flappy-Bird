#include"pipes.h"
#include<iostream>
using namespace std;


void Pipe::moveX() {
	SDL_Rect *r = getDest();
	r->x -= 2;
}

void Pipe::setPoz(bool t) {
	up = t;
}

void Pipe::setH() {
	SDL_Rect *r = getDest();
	r->h = rand() % 300 + 5;
}

void Pipe::setH2(int h) {
	SDL_Rect *r = getDest();
	r->h = rand() % (600 - h  - 200) + 5;
}

int Pipe::getX() {
	return (getDest()->x);
}

int  Pipe::getY() {
	return (getDest()->y);
}

int Pipe::getWidth() {
	return (getDest()->w);
}

int Pipe::getHeight() {
	return (getDest()->h);
}

void Pipe::render(SDL_Renderer* r) {
	SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
	SDL_Rect obstacleRect;
	if (up == 1)
		obstacleRect = {getX(), getY(), getWidth(), getHeight() }; else 
		obstacleRect = {getX(),getY(), getWidth(), -getHeight() };
	SDL_RenderFillRect(r, &obstacleRect);
}

bool Pipe::getUp() {
	return up;
}




