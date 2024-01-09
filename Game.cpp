#include"Game.h"
#include"Texture.h"
#include<iostream>
using namespace std;

Game::Game(int h, int w) {
	height = h;
	width = w;
	isRunning = false;
	window = NULL;
	renderer = NULL;
	player.setD(100, 200, 60, 70);
	time1 = 0;
	time2 = 0;
	freqMovingPipes = 1;
	freqPipes = 1;
	permission = true;
	game = false;
	speed = 2;
}

Game::~Game() {
	if (window != NULL) {
		delete window;
		window = nullptr;
	}
	if (renderer != NULL) {
		delete renderer;
		renderer = nullptr;
	}
}

void Game::init(const char* name, int x, int y, int width, int height) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		cout << "initializare cu succes" << endl;

		window = SDL_CreateWindow(name, x, y, width, height, 0);
		if (window) {

			cout << "fereastra s-a creat!" << endl;
		}
		else {

			isRunning = false;
			return;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {

			isRunning = true;
			cout << "render creat cu succes" << endl;
			player.CreateTexture("textures/player.png", renderer);
			background.CreateTexture("textures/background.bmp", renderer);
		}

	}
	else {

		cout << "initializarea nu s-a putut efectua" << endl;
		isRunning = false;
	}
}

void Game::saveGame() {

	//scriem datele pentru player in fisier
	player.write();

	//scriem datele pentru obstacole in fisier
	ofstream File("pipes.txt", std::ofstream::out | std::ofstream::trunc);
	for (auto& pipe : pipes) {
		File << pipe.first.getX() << ' ';
		File << pipe.first.getY() << ' ';
		File << pipe.first.getWidth() << ' ';
		File << pipe.first.getHeight() << ' ';
		File << pipe.first.getUp() << ' ';
		File << pipe.first.getType() << endl;

		File << pipe.second.getX() << ' ';
		File << pipe.second.getY() << ' ';
		File << pipe.second.getWidth() << ' ';
		File << pipe.second.getHeight() << ' ';
		File << pipe.second.getUp() << ' ';
		File << pipe.second.getType() << endl;
	}
	File.close();


	//scriem datele pentru game in fisier
	ofstream F("game.txt", std::ofstream::out | std::ofstream::trunc);
	F << time1 << endl;
	F << time2 << endl;
	F << freqMovingPipes << endl;
	F << freqPipes << endl;
	F << permission << endl;
	F.close();

	score.write();
}

void Game::loadGame() {

	//citim datele pentru player din fisier
	player.read();
	
	score.read();

	//citim datele pentru game din fisier si initializam membrii privati
	ifstream F("game.txt");
	if (F.is_open()) {
		F >> time1;
		F >> time2;
		F >> freqMovingPipes;
		F >> freqPipes;
		F >> permission;

		F.close();
	}

	//citim datele pentru obstacole si creeam vectorul cu obstacole
	pipes.clear();
	ifstream File("pipes.txt");
	if (File.is_open()) {

		int x, y, w, h; bool poz, type;
		while (File >> x >> y >> w >> h >> poz >> type) {

			MovePipe pipe;

			pipe.setD(x, y, h, w);
			//up/down
			pipe.setPoz(poz);
			//movePipe?
			if (type)
				pipe.setType();

			MovePipe pipe2;
			File >> x >> y >> w >> h >> poz >> type;

			pipe2.setD(x, y, h, w);
			pipe2.setPoz(poz);
			if (type)
				pipe2.setType();

			pipes.push_back({ pipe,pipe2 });
		}
		File.close();
	}
}


//functia care se apeleaza la click pe "New Game"
void Game::newGame() {
	score.resetScore();
	player.setD(100, 200, 60, 70);
	player.init();
	pipes.clear();
	time1 = 0;
	time2 = 0;
	freqMovingPipes = 1;
	freqPipes = 1;
	permission = true;
}


void Game::generatePipes() {

	time2 = ++freqPipes;
	if (time2 - time1 > 100) {

		MovePipe pipe;
		pipe.setD(800, 0, 0, 80);
		pipe.setPoz(1);

		MovePipe pipe2;
		pipe2.setD(800, 600, 0, 80);
		pipe2.setPoz(0);

		if (freqMovingPipes % 5 == 0) {

			pipe.setType();
			pipe2.setType();
			freqMovingPipes++;
		}

		pipe.setH();
		pipe2.setH2(pipe.getHeight());

		pipes.push_back({ pipe,pipe2 });
		freqPipes++;
		time1 = freqPipes;

		freqMovingPipes++;
	}
}

void Game::movePipesX(){
	for (pair<MovePipe, MovePipe>& pipe : pipes){
		pipe.first.moveX(speed); 
		pipe.second.moveX(speed);
	}
}

void Game::movePipesY(){
	for (pair<MovePipe, MovePipe>& pipe : pipes) {
		
		if (pipe.first.getType()) {

			if (pipe.first.getHeight() <= 0 && pipe.second.getHeight() <= 0)
				permission = true;

			if ((height - (pipe.first.getHeight() + pipe.second.getHeight()) > 100) && permission) {

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

bool Game::checkCollision(){

	for (auto &pipe : pipes){
				
		SDL_Rect *player_rect = player.getDest();

		if ((player_rect->x + player_rect->w) >= pipe.first.getX() && player_rect->x <= (pipe.first.getX() + pipe.first.getWidth())) {
			if (player_rect->y <= (pipe.first.getY() + pipe.first.getHeight())) {
				isRunning = false;
				break;
			}
		}

		if ((player_rect->x + player_rect->w) >= pipe.second.getX() && player_rect->x <= (pipe.second.getX() + pipe.second.getWidth())) {
			if ((player_rect->y + player_rect->h) >= (pipe.second.getY() - pipe.second.getHeight())) {
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
	player.GetJumpTime();
	if (event.type == SDL_QUIT) {
		isRunning = false;
	}

	//daca s-a apasat butonul
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);

		SDL_Rect startGameRect = { 300, 250, 150, 28 };
		if (menu.isMouseInsideRect(mouseX, mouseY, startGameRect)) {
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					isRunning = false;
				}
			}
			cout << "NewGame" << endl;
			game = true;
			newGame();
			return;
		}

		SDL_Rect loadRect = { 295, 300, 160, 28 };
		if (menu.isMouseInsideRect(mouseX, mouseY, loadRect)) {
			game = true;
			loadGame();
		}
	}

	//daca s-a apasat vreo tasta
	if (event.type == SDL_KEYDOWN)
	{

		if (event.key.keysym.sym == SDLK_UP)
		{
			player.Jump();
		}

		//tasta escape - se deschide meniul
		if (event.key.keysym.sym == SDLK_ESCAPE){
			game = false;
		}

		//tasta 's' - save Game
		if (event.key.keysym.sym == SDLK_s) {
			saveGame();
		}
		
	}
	else {
		if (game)
		player.Gravity();	
	}

}

void Game::nextLevel() {
	if (freqMovingPipes > 50 && freqMovingPipes < 100) {
		speed = 3;
	} else if (freqMovingPipes > 100) {
		speed = 4;
	}
}

void Game::update() {
	if (game) {
		nextLevel();
		generatePipes();
		movePipesX();
		movePipesY();
		checkCollision();
		score.updateScore();
	}
} 

void Game::render() {

	SDL_RenderClear(renderer);

	if (game) {
		background.render(renderer);
		player.render(renderer);

		for (auto& pipe : pipes) {
			pipe.first.render(renderer);
			pipe.second.render(renderer);
		}
		score.render(renderer);

	} else 
	menu.render(renderer);

	SDL_RenderPresent(renderer);
}

void Game::clean() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

	cout << "jocul s-a sters" << endl;
}

bool Game::running() {
	return isRunning;
}
