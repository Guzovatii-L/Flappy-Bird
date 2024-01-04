

#include "Score.h"

void Score::init() {

	TTF_Init();
	gFont = TTF_OpenFont("RubikScribble-Regular.ttf", 28);
	if (gFont == NULL) {
		printf("Error loading font: %s\n", TTF_GetError());
	}
}


SDL_Texture* Score::renderText(SDL_Renderer *r) {

	SDL_Color textColor = { 255, 255, 255 };
	string scoreText = to_string(score);

	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, scoreText.c_str(), textColor);
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

	score = SDL_GetTicks() / 1000;
}
