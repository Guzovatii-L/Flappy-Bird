#pragma once

#include"object.h"
#include <cstdlib>

class obstacle : public object{

private:

	bool up;

public:

	void moveX();
	void setH();
	void setPoz(bool up);
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	void setH2(int h);
	void render(SDL_Renderer* r);
	bool getUp();
};
