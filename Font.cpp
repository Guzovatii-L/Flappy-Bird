#include"Font.h"

Font::Font() {
    TTF_Init();
    gFont = TTF_OpenFont("RubikScribble-Regular.ttf", 28);
    if (gFont == NULL) {
        cout << "Error loading font: %s\n" << TTF_GetError();
    }
}

Font::~Font() {
    if (gFont != NULL) {
        delete gFont;
        gFont = NULL;
    }
}

TTF_Font* Font::getFont() {
    return gFont;
}
