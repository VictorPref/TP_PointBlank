//
// Created by prefo on 2018-12-17.
//
#include "Jeu.h"
#include "../utils/Utils.h"
const Uint8* kbStates = nullptr;
Uint32 mouseStates;
SDL_Event event;
int startTicks = 0, fixedupdateTicks = 0;
Camera* camera = nullptr;

void Jeu::initialisation()
{
	SDL_GLContext context;
	isRunning = true;
	timeOfDay = 9;
	srand(time(NULL));
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	win = SDL_CreateWindow("Point Blank",SDL_WINDOWPOS_UNDEFINED,
	                       SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	context = SDL_GL_CreateContext(win);
	SDL_GL_SetSwapInterval(10);
	glEnable(GL_DEPTH_TEST);
	//activer le texuring
	glEnable(GL_TEXTURE_2D);
	Utils::GenerateWorld(timeOfDay);
	playerManager = PlayerManager::getInstance();
	camera = new Camera();
}

void Jeu::demarrerJeu(){
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	while(isRunning) {
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Update();
		//if(SDL_GetTicks() - fixedupdateTicks)
		dessinerSurRender();
		Vector3 v3(0,0,0);
		
	
		
		camera->Look(v3);
		glFlush();
		SDL_GL_SwapWindow(win);
		SDL_Delay(16);
	}
}
void Jeu::nettoyer()
{

}
void Jeu::effacer(){}
void Jeu::dessinerSurRender(){

	
	
	Utils::DrawSkybox();
	playerManager->drawPlayers();
}
void Jeu::Update(){
	//les événements
	SDL_PollEvent(&event);
	kbStates = SDL_GetKeyboardState(NULL);
	
	if (event.type == SDL_QUIT) {
		isRunning = false;
	}
	
	//update du modele
	playerManager->UpdateAllPlayers(this);
	camera->Update();
	
}