//
// Created by Jean-François on 12/17/2018.
//

#ifndef TEST_MENU_MENU_H
#define TEST_MENU_MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <string>

class Menu {

private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    int width, height;
    int titlePosX, titlePosY;
    bool  isRunning = false;
    int selectedMenuItem = 0;
    int selectionImageSize;
    SDL_Surface* surfImgBackground = nullptr;
    SDL_Texture* textureImgBackground = nullptr;

    SDL_Surface* surfImgSelection = nullptr;
    SDL_Texture* textureImgSelection= nullptr;

    TTF_Font* font = nullptr;
    Mix_Chunk *gMusic = nullptr;
    SDL_Joystick* gGameController = nullptr;

    void Erase();
    void UpdateModel(SDL_Event* event);
    void Draw();
    void UpdateScreen();

    void DrawBackground();
    void DrawTitle();
    void DrawMenuOptions();

public:
    void Init();
    void Start();
    void Clean();

    Menu();

    Menu(int width, int height);

    virtual ~Menu();

    SDL_Window *getWindow() const;

    int getWidth() const;

    int getHeight() const;

    int getSelectedMenuItem() const;
};


#endif //TEST_MENU_MENU_H
