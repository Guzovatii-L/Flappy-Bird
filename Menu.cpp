
#include"Menu.h"

void Menu::renderText(const char* text, int x, int y, SDL_Renderer *r, SDL_Color textColor) {


    SDL_Surface* surface = TTF_RenderText_Solid(gFont, text, textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(r, surface);

    int width = 50, height = 50;
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    SDL_Rect dstRect = { x, y, width, height };
    SDL_RenderCopy(r, texture, nullptr, &dstRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

}

void Menu::init() {

    TTF_Init();
    gFont = TTF_OpenFont("RubikScribble-Regular.ttf", 28);
    if (gFont == NULL) {
        printf("Error loading font: %s\n", TTF_GetError());
    }
}

bool Menu::isMouseInsideRect(int mouseX, int mouseY, const SDL_Rect& rect) {
    return mouseX >= rect.x && mouseX <= rect.x + rect.w && mouseY >= rect.y && mouseY <= rect.y + rect.h;
}

void Menu::render(SDL_Renderer *r) {

    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
    
    SDL_Rect backgroundRect;
    backgroundRect = {0, 0, 800, 600};
    SDL_RenderFillRect(r, &backgroundRect);

    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_Rect startGameRect = { 300, 250, 150, 28 };
    SDL_Rect loadRect = { 295, 300, 160, 28 };

    if (isMouseInsideRect(mouseX, mouseY, startGameRect))
        renderText("New Game", 300, 250, r, color2); else
        renderText("New Game", 300, 250, r, color1);

    if (isMouseInsideRect(mouseX, mouseY, loadRect))
        renderText("Load Game", 295, 300, r, color2); else
        renderText("Load Game", 295, 300, r, color1);
}
