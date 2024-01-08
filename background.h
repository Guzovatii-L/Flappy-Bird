#pragma once
#include"object.h"

class Background : public Object {
private:
public:
	Background();
	void render(SDL_Renderer* r);
};
