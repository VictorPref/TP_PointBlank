//
// Created by prefo on 2018-12-17.
//
#include "Jeu.h"
void Jeu::initialisation()
{
	SDL_GLContext context;
	bool isRunning = true;
	
	srand(time(NULL));
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	win = SDL_CreateWindow("OpenGl Test", SDL_WINDOWPOS_CENTERED,
	                       SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	context = SDL_GL_CreateContext(win);
	SDL_GL_SetSwapInterval(10);
	//charger la matrice de transformation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)800/600, 1, 1000);
	glEnable(GL_DEPTH_TEST);
	//activer le texuring
	glEnable(GL_TEXTURE_2D);
	
}

void Jeu::demarrerJeu(){


}
void Jeu::nettoyer()
{

}
void Jeu::effacer(){}
void Jeu::dessinerSurRender(){}
void Jeu::Update(){}