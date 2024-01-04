#pragma once
#include"SDL.h"
#include"SDL_image.h"
#include<vector>
#include"player.h"
#include"background.h"
#include"pipes.h"
#include"pipes_move.h"
#include<string>
#include"Score.h"
#include <fstream>
using namespace std;

class Game {

private:

	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Player p;
	background b;
	vector<pair<obstacle2, obstacle2>>pipes;
	Score s;
	int time1;
	int time2;
	int freq = 1;
	bool permission = true;

public:

	Game();
	~Game();

	void init(const char *name, int x, int y, int width, int height);
	void handleEvents();
	void update();
	void render();
	void clean();
	void generatePipes();
	bool running();
	void movePipesX();
	void movePipesY();
	bool checkCollision();
};
