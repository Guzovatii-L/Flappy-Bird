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
#include"Menu.h"
#include <stdexcept>
using namespace std;

class Game {
private:
	int height;
	int width;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Player player;
	Background background;
	vector<pair<MovePipe, MovePipe>>pipes;
	Score score;
	int time1;
	int time2;
	int freqMovingPipes;
	int freqPipes;
	bool permission;
	Menu menu;
	bool game;
	int speed;
public:

	Game(int, int);
	~Game();

	void init(const char *name, int x, int y, int width, int height);
	void handleEvents();
	void update();
	void render();
	void generatePipes();
	bool running();
	void movePipesX();
	void movePipesY();
	bool checkCollision();
	void loadGame();
	void newGame();
	void saveGame();
	void nextLevel();
};
