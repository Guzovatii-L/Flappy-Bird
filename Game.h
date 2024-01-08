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
	int time1 = 0;
	int time2 = 0;
	int freqMovingPipes = 1;
	int freqPipes = 1;
	bool permission = true;
	Menu menu;
	bool newGame = false;
	bool loadGame = false;
public:

	Game(int, int);
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
	void LoadGame();
	void NewGame();
	void saveGame();

};
