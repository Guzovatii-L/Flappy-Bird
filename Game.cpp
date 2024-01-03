

#include"Game.h"
#include"Texture.h"
#include<iostream>
using namespace std;


Game::Game() {

	isRunning = false;
	window = NULL;
	renderer = NULL;
	//p.setS(0, 0, 24, 32);
	p.setD(100, 200, 60, 70);
}

Game::~Game() {
}

void Game::init(const char* name, int x, int y, int width, int height) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		cout << "initializare cu succes" << endl;

		window = SDL_CreateWindow(name, x, y, width, height, 0);
		if (window) {

			cout << "fereastra s-a creat!" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {

			isRunning = true;
			cout << "render creat cu succes" << endl;
			p.CreateTexture("textures/player.png", renderer);
			b.CreateTexture("textures/background.bmp", renderer);

		}

	}
	else {

		cout << "initializarea nu s-a putut efectua" << endl;
		isRunning = false;
	}
}

void Game::generatePipes() {

	int time2 = SDL_GetTicks();
	if (time2 - time1 > 2200) {

		obstacle2 pipe;
		pipe.setD(800, 0, 0, 80);
		obstacle2 pipe2;
		pipe2.setD(800, 600, 0, 80);

		if (freq % 5 == 0) {

			pipe.setType();
			pipe2.setType();
		}

		pipe.setH();
		pipe2.setH2(pipe.getHeight());

		pipes.push_back({ pipe,pipe2 });
		time1 = SDL_GetTicks();

		freq++;
	}
}

void Game::movePipesX()
{
	for (pair<obstacle2, obstacle2>& pipe : pipes){
		pipe.first.moveX(); 
		pipe.second.moveX();
	}
}

void Game::movePipesY()
{
	for (pair<obstacle2, obstacle2>& pipe : pipes) {
		
		if (pipe.first.getType()) {

			if (pipe.first.getHeight() <= 0 && pipe.second.getHeight() <= 0)
				permission = true;

			if ((600 - (pipe.first.getHeight() + pipe.second.getHeight()) > 100) && permission) {

				pipe.first.moveY(3);
				pipe.second.moveY(3);
			}
			else {

				pipe.first.moveY(-3);
				pipe.second.moveY(-3);

				permission = false;
			}
		}
	}
}

bool Game::checkCollision()
{
	for (auto &pipe : pipes){
				
		SDL_Rect *r = p.getDest();

		if ((r->x + r->w) >= pipe.first.getX() && r->x <= (pipe.first.getX() + pipe.first.getWidth())) {
			if (r->y <= (pipe.first.getY() + pipe.first.getHeight())) {
					isRunning = false;
					break;
			}
		}

		if ((r->x + r->w) >= pipe.second.getX() && r->x <= (pipe.second.getX() + pipe.second.getWidth())) {
			if ((r->y + r->h) >= (pipe.second.getY() - pipe.second.getHeight())) {
				isRunning = false;					
				break;
			}
		}
	}
	return false;
}



void Game::handleEvents() {

	SDL_Event event;
	SDL_PollEvent(&event);
	p.GetJumpTime();
	if (event.type == SDL_QUIT) {
		isRunning = false;
	}
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_UP)
		{
			p.Jump();
		}
	}
	else {
		p.Gravity();
	}



}

void Game::update() {
	generatePipes();
	movePipesX();
	movePipesY();
	checkCollision();
} 

void Game::render() {

	SDL_RenderClear(renderer);
	b.render(renderer);
	p.render(renderer);

	// Render obstacles
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	for (auto& pipe : pipes) {
		SDL_Rect obstacleRect, obstacleRect2;
			obstacleRect = { pipe.first.getX(), pipe.first.getY(), pipe.first.getWidth(), pipe.first.getHeight() }; 
			obstacleRect2 = { pipe.second.getX(), pipe.second.getY(), pipe.second.getWidth(), -pipe.second.getHeight() }; 
		SDL_RenderFillRect(renderer, &obstacleRect);
		SDL_RenderFillRect(renderer, &obstacleRect2);

	}

	SDL_RenderPresent(renderer);
}

void Game::clean() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	cout << "jocul s-a sters" << endl;
}

bool Game::running() {
	return isRunning;
}


