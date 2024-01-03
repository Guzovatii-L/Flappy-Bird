
#include"player.h"
#include<iostream>
using namespace std;

void Player::render(SDL_Renderer* r) {

	SDL_Rect s = getSrc();
	SDL_Rect *d = getDest();

	SDL_RenderCopy(r, getTexture(), NULL, d);
}

void Player::Gravity() {

	if (jumpState())
	{
		acc1 = acc1 + 0.025;
		acc2 = acc2 + 0.025;
		jHeight = jHeight + gravity;
		Ypos = Ypos + gravity + acc1 + acc2 + jHeight;
		setD(25, Ypos, 28, 38);
		if (jHeight > 0)
		{
			jump = false;
			jHeight = -6;
		}
	}
	else
	{

		acc1 = acc1 + 0.035;
		acc2 = acc2 + 0.035;
		Ypos = Ypos + gravity + acc1 + acc2;
		setD(25, Ypos, 28, 38);
	}
}

void Player::GetJumpTime() {

	jumpTimer = SDL_GetTicks();

}

void Player::Jump() {
	acc1 = 0;
	acc2 = 0;
	jump = true;
	lastJump = jumpTimer;
	jHeight = -6;
	/*if (jumpTimer - lastJump > 20)
	{
		acc1 = 0;
		acc2 = 0;
		jump = true;
		lastJump = jumpTimer;
	}
	else
	{
		Gravity();
	}*/
}


bool Player::jumpState() {

	return jump;
}
