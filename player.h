#pragma once
#include"object.h"

class Player : public Object {
private:
	double Ypos;
	double gravity;
	double acc1;
	double acc2;
	bool jump;
	double jHeight;
	double lastJump;
	double jumpTimer;
public:
	Player();
	~Player();
	void init();
	void Gravity();
	void GetJumpTime();
	void Jump();
	bool jumpState();
	void render(SDL_Renderer* r);
	void write();
	void read();
};