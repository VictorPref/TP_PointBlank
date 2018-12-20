//
// Created by prefo on 2018-12-17.
//
#include "Jeu.h"
#include "../utils/Utils.h"
const Uint8* kbStates = nullptr;
Uint32 mouseStates;
SDL_Event event;
int startTicks = 0, fixedupdateTicks = 0;

void Jeu::initialisation()
{
	SDL_GLContext context;
	isRunning = true;
	timeOfDay = 9;
	srand(time(NULL));
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	win = SDL_CreateWindow("Point Blank", SDL_WINDOWPOS_CENTERED,
	                       SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	context = SDL_GL_CreateContext(win);
	SDL_GL_SetSwapInterval(10);
	glEnable(GL_DEPTH_TEST);
	//activer le texuring
	glEnable(GL_TEXTURE_2D);
	Utils::GenerateWorld(timeOfDay);
	playerManager = PlayerManager::getInstance();
}

void Jeu::demarrerJeu(){
	while(isRunning) {
		Update();
		//if(SDL_GetTicks() - fixedupdateTicks)
		dessinerSurRender();
		SDL_Delay(16);
	}
}
void Jeu::nettoyer()
{

}
void Jeu::effacer(){}
void Jeu::dessinerSurRender(){
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	Utils::DrawSkybox();
	playerManager->drawPlayers();
	
	//camera.look()
}
void Jeu::Update(){
	//les événements
	SDL_PollEvent(&event);
	kbStates = SDL_GetKeyboardState(NULL);
	
	if (event.type == SDL_QUIT) {
		isRunning = false;
	}
	
	//update du modele
	playerManager->UpdateAllPlayers();
	
}