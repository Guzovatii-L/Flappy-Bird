#pragma once
#include"object.h"

class Player : public object {

private:
	double Ypos = 256;
	double gravity = 0.2;
	double acc1 = 0;
	double acc2 = 0;
	bool jump = false;
	double jHeight = -6;
	double lastJump = 0;
	double jumpTimer;
public:
	void Gravity();
	void GetJumpTime();
	void Jump();
	bool jumpState();
	void render(SDL_Renderer* r);
	void write();
	void read();

};