#include "Score.h"

Score::Score():Font() {
	score = 0;
	scoreTimer = 0;
}

Score::~Score() {
}

void Score::resetScore() {
	score = 0;
}

void Score::write() {
	ofstream File("score.txt", std::ofstream::out | std::ofstream::trunc);
	File << score << endl;
	File.close();
}

void Score::read() {
	ifstream File("score.txt");
	if (File.is_open()) {
		File >> score;
		File.close();
	}
}

SDL_Texture* Score::renderText(SDL_Renderer *r) {
	SDL_Color textColor = { 255, 255, 255 };
	string scoreText = to_string(score);

	SDL_Surface* textSurface = TTF_RenderText_Solid(getFont(), scoreText.c_str(), textColor);
	if (textSurface == NULL) {
		cout << "textS is null" << endl;
		return NULL;
	}

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(r, textSurface);
	if (textTexture == NULL) {
		cout << "texture is 0" << endl;
		SDL_FreeSurface(textSurface);
		return NULL;
	}

	SDL_FreeSurface(textSurface);
	return textTexture;
}

void Score::render(SDL_Renderer* r) {
	string scoreText = to_string(score);
	SDL_Texture* textTexture = renderText(r);
	if (textTexture != NULL) {
		SDL_Rect destRect = { 10, 10, scoreText.length() * 40, 60 };
		SDL_RenderCopy(r, textTexture, NULL, &destRect);
		SDL_DestroyTexture(textTexture);
	}
}


void Score::updateScore() {
	if (SDL_GetTicks() - scoreTimer > 1000) {
		score++;
		scoreTimer = SDL_GetTicks();
	}
}
