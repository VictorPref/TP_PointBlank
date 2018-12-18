//
// Created by Jean-François on 12/17/2018.
//

#include "Menu.h"

Menu::Menu() {
    width = 1024;
    height = 768;

    surfImgBackground = IMG_Load("assets/img/background.jpg");
    if(!surfImgBackground){
        printf("error");
    }

    surfImgSelection = IMG_Load("assets/img/bullet.png");
    if(!surfImgSelection){
        printf("error");
    }

}

Menu::~Menu() {

}

void Menu::Erase() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Menu::UpdateModel(SDL_Event *event) {

    Input input = InputManager::getInstance()->GetKeysInput(gGameController);

    if(event->type == SDL_QUIT){
        isRunning = false;
        selectedMenuItem = -1;
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);

    /**
     * Joystick
     */
    if(gGameController)
    {

        if( SDL_JoystickGetAxis(gGameController, 1) < -10000 )
        {
         if(selectedMenuItem == 1)
                selectedMenuItem--;

        }
        else if( SDL_JoystickGetAxis(gGameController, 1) > 10000 )
        {
            if(selectedMenuItem == 0)
                selectedMenuItem++;
        }


        if(SDL_JoystickGetButton(gGameController, SDL_CONTROLLER_BUTTON_A) > 0 )
        {
            isRunning = false;
        }

        if( SDL_JoystickGetAxis(gGameController, 3) > 10000 )
        {
            input.Show();
        }
    }

    /**
     * Keyboard
     */
    if (state[SDL_SCANCODE_W]) {
        if(selectedMenuItem == 1)
            selectedMenuItem--;
    }

    if (state[SDL_SCANCODE_S]) {
        if(selectedMenuItem == 0)
            selectedMenuItem++;
    }

    if (event->type == SDL_KEYDOWN) {

        if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
        {
            isRunning = false;
        }
    }

}

void Menu::Draw() {

    DrawBackground();
    DrawTitle();
    DrawMenuOptions();
}

void Menu::UpdateScreen() {
    SDL_RenderPresent(renderer);
}

void Menu::Init() {

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
    TTF_Init();

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }

    gMusic = Mix_LoadWAV("assets/music/background.wav");
    if(!gMusic)
    {
        printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
    }


    SDL_CreateWindowAndRenderer(width, height, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC, &window,
                                &renderer);
    isRunning = true;

    if( SDL_NumJoysticks() < 1 )
    {
        printf( "Warning: No joysticks connected!\n" );
    }
    else
    {
        //Load joystick
        gGameController = SDL_JoystickOpen( 0 );
        if( gGameController == NULL )
        {
            printf( "Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError() );
        }
    }

    selectionImageSize =  width/18;
}

void Menu::Start() {

    Mix_PlayChannel(0,gMusic,-1);
    SDL_Event event;
    Uint32 startTime, endTime;
    while (isRunning) {
        startTime = SDL_GetTicks();
        SDL_PollEvent(&event);
        Erase();
        UpdateModel(&event);
        Draw();
        endTime = SDL_GetTicks();
        if(endTime - startTime < 1000/60)
            SDL_Delay((1000/60)-(endTime - startTime));
        UpdateScreen();
    }
}

void Menu::Clean() {

    SDL_DestroyTexture(textureImgBackground);
    SDL_DestroyTexture(textureImgSelection);
    SDL_JoystickClose( gGameController );
    Mix_FreeChunk(gMusic);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    //SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Menu::DrawTitle() {

    font = TTF_OpenFont("assets/font/font.ttf", width/9);
    if(!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }

    SDL_Color color = {255,0,0,255};
    std::string title = "Point Blank";
    SDL_Surface* surfTmp = TTF_RenderText_Solid(font,title.c_str(),color );

    int w = width;
    int h = 125;
    TTF_SizeText(font,"",&w,&h);

    SDL_Texture* text = SDL_CreateTextureFromSurface(renderer,surfTmp);

    SDL_Rect r = {width/5,height/11,surfTmp->w,surfTmp->h};
    SDL_RenderCopy(renderer,text, NULL, &r);

    SDL_FreeSurface(surfTmp);
    SDL_DestroyTexture(text);
}

void Menu::DrawMenuOptions() {



    font = TTF_OpenFont("assets/font/font.ttf", selectionImageSize);
    if(!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }

    //OptionStart

    SDL_Color color = {0,0,0,255};
    std::string title = "Start";
    SDL_Surface* surfTmp = TTF_RenderText_Solid(font,title.c_str(),color );

    int w = 175;
    int h = 50;

    TTF_SizeText(font,"",&w,&h);

    SDL_Texture* text = SDL_CreateTextureFromSurface(renderer,surfTmp);

    SDL_Rect r = {width/3+selectionImageSize,height/2,surfTmp->w,surfTmp->h};
    SDL_RenderCopy(renderer,text, NULL, &r);

    SDL_FreeSurface(surfTmp);
    SDL_DestroyTexture(text);

    //OptionQuit
    title = "Quit";
    surfTmp = TTF_RenderText_Solid(font,title.c_str(),color );

    TTF_SizeText(font,"",&w,&h);

    text = SDL_CreateTextureFromSurface(renderer,surfTmp);

    r = {width/3+selectionImageSize,height/2+height/6,surfTmp->w,surfTmp->h};
    SDL_RenderCopy(renderer,text, NULL, &r);

    SDL_FreeSurface(surfTmp);
    SDL_DestroyTexture(text);


    //Selection
    if(selectedMenuItem == 0)
    {
        if(!textureImgSelection)
        {
            textureImgSelection = SDL_CreateTextureFromSurface(renderer, surfImgSelection);
            SDL_FreeSurface(surfImgSelection);
        }

        SDL_Rect r = {width/3+width/15-selectionImageSize,height/2+selectionImageSize/6,selectionImageSize,selectionImageSize};

        SDL_RenderCopy(renderer, textureImgSelection, NULL,&r);
    }
    else
    {
        if(!textureImgSelection)
        {
            textureImgSelection = SDL_CreateTextureFromSurface(renderer, surfImgSelection);
            SDL_FreeSurface(surfImgSelection);
        }

        SDL_Rect r = {width/3+width/15-selectionImageSize,height/2+height/6+selectionImageSize/6,selectionImageSize,selectionImageSize};

        SDL_RenderCopy(renderer, textureImgSelection, NULL,&r);
    }
}

void Menu::DrawBackground() {
    if(!textureImgBackground)
    {
        textureImgBackground = SDL_CreateTextureFromSurface(renderer, surfImgBackground);
        SDL_FreeSurface(surfImgBackground);
    }

    SDL_Rect r = {0,0,width,height};

    SDL_RenderCopy(renderer, textureImgBackground, NULL,&r);
}

SDL_Window *Menu::getWindow() const {
    return window;
}

int Menu::getWidth() const {
    return width;
}

int Menu::getHeight() const {
    return height;
}

Menu::Menu(int width, int height) : width(width), height(height) {

    surfImgBackground = IMG_Load("assets/img/background.jpg");
    if(!surfImgBackground){
        printf("error");
    }

    surfImgSelection = IMG_Load("assets/img/bullet.png");
    if(!surfImgSelection){
        printf("error");
    }
}

int Menu::getSelectedMenuItem() const {
    return selectedMenuItem;
}
