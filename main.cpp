#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "Game.h"

int main(int argc, char* args[]) {

	const int FPS = 50;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Game* game = new Game(600, 800);

	game->init("joc", 200, 200, 800, 600);


	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {

			SDL_Delay(frameDelay - frameTime);
		}


	}

	game->clean();

	return 0;
}

