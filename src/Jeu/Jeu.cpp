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
	isRunning = true;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	win = SDL_CreateWindow("OpenGl Test", SDL_WINDOWPOS_CENTERED,
						   SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	context = SDL_GL_CreateContext(win);
	//   SDL_GL_SetSwapInterval(10);
	//charger la matrice de transformation

	glEnable(GL_DEPTH_TEST);
		SDL_Event event;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// gluLookAt(100,100,100,0,0,0,0,0,1);


	//   player = new Player(Vector3(0,0,60),Vector3(10,10,10),Vector3(0,0,0),Vector3(250,120,40),0);
	sol = new Cube (Vector3(-60,-100,0),Vector3(300,300,1),Vector3(0,0,0),Vector3(120,40,250));

	//  Cube* testCollision = new Cube (Vector3(0,0,0),Vector3(20,20,20),Vector3(0,0,0),Vector3(255,0,0));

	playerManager= PlayerManager::getInstance();
	std::vector<Vector3> spawnPos;
	spawnPos.push_back(Vector3(0,0,40));
	spawnPos.push_back(Vector3(20,0,40));
	playerManager->CreatePlayer(spawnPos);


	SDL_Joystick* gGameController = nullptr;
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

	//player->setController(gGameController);


	bulletManager = BulletManager::getInstance();

	Utils::MakeSkybox(2,100,0,0,0);

	SDL_SetWindowFullscreen(win,
							SDL_WINDOW_FULLSCREEN);

}

void Jeu::demarrerJeu(){

	std::vector<GameObject*> levels;
	levels.push_back(sol);

	while (isRunning) {

		glViewport(0, 1080/2, 1920, 1080/2);
		//effacer le tampon d’affichage

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(65,(double)1920/1080,1,1000);

		glClearColor(1.f, 1.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



		//gestion evenement
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				isRunning = false;

		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		const Uint8 *state = SDL_GetKeyboardState(NULL);


		//dessiner sur le buffer



		//	player->Update(levels);
		playerManager->UpdatePlayer(0, levels);

		Utils::DrawSkybox();
		//player->draw();
		playerManager->drawPlayer(1);
		sol->draw();

		bulletManager->DrawBullets();

		playerManager->DrawUIPlayer(0);


		glViewport(0, 0, 1920, 1080/2);
		//effacer le tampon d’affichage

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(65,(double)1920/1080,1,1000);


		//gestion evenement
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				isRunning = false;

		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		state = SDL_GetKeyboardState(NULL);


		//dessiner sur le buffer

		//	player->Update(levels);
		//playerManager->UpdateAllPlayers(levels);
		playerManager->UpdatePlayer(1, levels);

		Utils::DrawSkybox();
		//player->draw();
		playerManager->drawPlayer(0);
		sol->draw();

		bulletManager->DrawBullets();

		playerManager->DrawUIPlayer(1);

		bulletManager->UpdateBullets();
		//pause
		SDL_Delay(15);
		//mise a jour de l'ecran
		glFlush();
		SDL_GL_SwapWindow(win);
	}

}
void Jeu::nettoyer()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
void Jeu::effacer(){}
void Jeu::dessinerSurRender(){

	//Utils::DrawSkybox();
	sol->draw();
	playerManager->drawPlayers();
	bulletManager->DrawBullets();

}
void Jeu::Update(){
	//les événements
	SDL_PollEvent(&event);
	kbStates = SDL_GetKeyboardState(NULL);

	if (event.type == SDL_QUIT) {
		isRunning = false;
	}

	//update du modele
	//playerManager->UpdateAllPlayers(this);
	bulletManager->UpdateBullets();

}

Jeu::~Jeu() {
delete sol;
}
