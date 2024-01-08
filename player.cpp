#include"player.h"

Player::Player() {
	Ypos = 256;
	gravity = 0.2;
	acc1 = 0;
	acc2 = 0;
	jump = false;
	jHeight = -6;
	lastJump = 0;
	jumpTimer = 0;
}

Player::~Player() {
}

//functie pentru new game
void Player::init() {
	Ypos = 256;
	acc1 = 0;
	acc2 = 0;
	jump = false;
	jHeight = -6;
	lastJump = 0;
}

void Player::render(SDL_Renderer* r) {
	SDL_Rect *d = getDest();
	SDL_RenderCopy(r, getTexture(), NULL, d);
}

void Player::Gravity() {

	if (jumpState()){
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
	else{
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
}

bool Player::jumpState() {
	return jump;
}

void Player::write() {
	ofstream File("player.txt", std::ofstream::out | std::ofstream::trunc);

	File << Ypos << endl;
	File << acc1 << endl;
	File << acc2 << endl;
	File << jump << endl;
	File << jHeight << endl;
	File << lastJump << endl;
	File << jumpTimer << endl;

	File.close();
}

void Player::read() {
	ifstream File("player.txt");

	if (File.is_open()) {
		File >> Ypos;
		File >> acc1;
		File >> acc2;
		File >> jump;
		File >> jHeight;
		File >> lastJump;
		File >> jumpTimer;

		File.close();
	}
}
