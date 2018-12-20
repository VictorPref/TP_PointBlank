//
// Created by cchevret on 2018-12-12.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <dbghelp.h>
#include <vector>
#include <random>
#include <time.h>
#include "Utils.h"
#include "sdlglutils.h"
#include "../GameObject/Primitive/Cube.h"

std::vector<GameObject*> Utils::level;
void Utils::MakeWhiteSquare(float w, float h, float x, float y, float angle, bool darker)
{
	int clr = 255;
	if(darker)
		clr = 0;
	
	
	glPushMatrix();
	glTranslated(x, y , 0 );
	glRotated(angle, 0, 0, 1);
	glBegin(GL_QUADS);
	glColor3ub(clr, clr, clr);
	glVertex2d(0,0);
	glVertex2d(w, 0);
	glVertex2d(w, h);
	glVertex2d(0, h);
	glColor3ub(clr, clr, clr);
	glVertex2d(w - h, 0);
	glVertex2d(w, 0);
	glVertex2d(w, w);
	glVertex2d(w - h, w);
	glColor3ub(clr, clr, clr);
	glVertex2d(w, w - h);
	glVertex2d(w, w);
	glVertex2d(0, w);
	glVertex2d(0, w - h);
	glColor3ub(clr, clr, clr);
	glVertex2d(0, 0);
	glVertex2d(h, 0);
	glVertex2d(h, w);
	glVertex2d(0, w);
	glEnd();
	glRotated(45, 0, 0, 1);
	glBegin(GL_QUADS);
	glColor3ub(clr, clr, clr);
	glVertex2d(0,0);
	glVertex2d(w, 0);
	glVertex2d(w, h);
	glVertex2d(0, h);
	glColor3ub(clr, clr, clr);
	glVertex2d(w - h, 0);
	glVertex2d(w, 0);
	glVertex2d(w, w);
	glVertex2d(w - h, w);
	glColor3ub(clr, clr, clr);
	glVertex2d(w, w - h);
	glVertex2d(w, w);
	glVertex2d(0, w);
	glVertex2d(0, w - h);
	glColor3ub(clr, clr, clr);
	glVertex2d(0, 0);
	glVertex2d(h, 0);
	glVertex2d(h, w);
	glVertex2d(0, w);
	glEnd();
	glPopMatrix();
}

void Utils::GenerateWorld(int timeOfDay)
{
	std::vector<GameObject*> cubeList;
	std::vector<GameObject*> cubeList2;
	for (int i = 0; i < 18; i++) {
		for (int k = 0; k < 8; k++) {
			int r = 1;
			if (i < 2) {
				r *= rand() % 3 + 7;
				SDL_Delay(1);
				
			} else if (i < 6) {
				r *= rand() % 3 + 4;
				SDL_Delay(1);
				
			} else {
				r *= rand() % 3 + 1;
				SDL_Delay(1);
				
			}
			
			Vector3 transform(k, i - 20, 0);
			Vector3 scale(4, 4, r);
			Vector3 rotation(0, 0, 0);
			Vector3 color(255, 255, 255);
			
			Cube* c = new Cube(transform, scale, rotation, "assets/textures/txt_platform_short.jpg", 1);
			cubeList.push_back(c);
		}
	}
	
	
	for (int n = 18; n > 0; n--) {
		for (int b = 8; b > 0; b--) {
			int m = 1;
			if (n < 2) {
				m *= rand() % 3 + 7;
				SDL_Delay(1);
				
			} else if (n < 6) {
				m *= rand() % 3 + 4;
				SDL_Delay(1);
				
			} else {
				m *= rand() % 3 + 1;
				SDL_Delay(1);
			}
			
			Vector3 transform(b, n , 0);
			Vector3 scale(4,4,m);
			Vector3 rotation(0,0,0);
			Vector3 color(255, 255, 255);
			
			Cube* c = new Cube(transform, scale, rotation, "assets/textures/txt_platform_short.jpg", 1);
			cubeList2.push_back(c);
		}
	}
	
	{
		//brouillard ground
		glPushMatrix();
		glTranslated(0, 0, -150);
		glBegin(GL_QUADS);
		glColor4b(0, 0, 0, 0.8f);
		glVertex3d(175, 175, 0);
		glVertex3d(-175, 175, 0);
		glVertex3d(-175, -175, 0);
		glVertex3d(175, -175, 0);
		glTranslated(0, 0, 80);
		
		glColor4b(150, 150, 150, 150);
		glVertex3d(175, 175, 20);
		glVertex3d(-175, 175, 20);
		glVertex3d(-175, -175, 20);
		glVertex3d(175, -175, 20);
		glEnd();
		glPopMatrix();
		//end brouillard
		
		//effacer le tampon d’affichage
		for (GameObject *c : cubeList) {
			level.push_back(c);
		}
		
		//glPushMatrix();
		//glTranslated(12.5, 35, 0);
	//	glRotated(180, 0, 0, 1);
		for (GameObject *c : cubeList2) {
			Vector3 t(12.5,35,0);
			Vector3 q =c->getTransform();
			c->setTransform(q+t);
			c->setRotation(Vector3(0,0,180));
			level.push_back(c);
		}
		
	//	glPopMatrix();
	}
}

void Utils::DrawSkybox()
{
	for(GameObject* go : level)
	{
		go->draw();
	}
	
}

void Utils::MakeSkybox(int timeOfDay, float w, float x, float y, float angle) {
	GLuint textureId_bk;
	GLuint textureId_dn;
	GLuint textureId_ft;
	GLuint textureId_lf;
	GLuint textureId_rt;
	GLuint textureId_up;
	switch (timeOfDay)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			textureId_bk = loadTexture("assets/hw_nightsky/nightsky_bk.png");
			textureId_dn = loadTexture("assets/hw_nightsky/nightsky_dn.png");
			textureId_ft = loadTexture("assets/hw_nightsky/nightsky_ft.png");
			textureId_lf = loadTexture("assets/hw_nightsky/nightsky_lf.png");
			textureId_rt = loadTexture("assets/hw_nightsky/nightsky_rt.png");
			textureId_up = loadTexture("assets/hw_nightsky/nightsky_up.png");
			break;
		case 7:
		case 8:
		case 9:
			textureId_bk = loadTexture("assets/mp_met/met_bk.png");
			textureId_dn = loadTexture("assets/mp_met/met_dn.png");
			textureId_ft = loadTexture("assets/mp_met/met_ft.png");
			textureId_lf = loadTexture("assets/mp_met/met_lf.png");
			textureId_rt = loadTexture("assets/mp_met/met_rt.png");
			textureId_up = loadTexture("assets/mp_met/met_up.png");
			break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
			textureId_bk = loadTexture("assets/ame_ash/ashcanyon_bk.png");
			textureId_dn = loadTexture("assets/ame_ash/ashcanyon_dn.png");
			textureId_ft = loadTexture("assets/ame_ash/ashcanyon_ft.png");
			textureId_lf = loadTexture("assets/ame_ash/ashcanyon_lf.png");
			textureId_rt = loadTexture("assets/ame_ash/ashcanyon_rt.png");
			textureId_up = loadTexture("assets/ame_ash/ashcanyon_up.png");
			break;
		case 19:
		case 20:
			textureId_bk = loadTexture("assets/ely_sunset/sunset_bk.png");
			textureId_dn = loadTexture("assets/ely_sunset/sunset_dn.png");
			textureId_ft = loadTexture("assets/ely_sunset/sunset_ft.png");
			textureId_lf = loadTexture("assets/ely_sunset/sunset_lf.png");
			textureId_rt = loadTexture("assets/ely_sunset/sunset_rt.png");
			textureId_up = loadTexture("assets/ely_sunset/sunset_up.png");
			break;
		case 21:
		case 22:
		case 23:
			textureId_bk = loadTexture("assets/hw_nightsky/nightsky_bk.png");
			textureId_dn = loadTexture("assets/hw_nightsky/nightsky_dn.png");
			textureId_ft = loadTexture("assets/hw_nightsky/nightsky_ft.png");
			textureId_lf = loadTexture("assets/hw_nightsky/nightsky_lf.png");
			textureId_rt = loadTexture("assets/hw_nightsky/nightsky_rt.png");
			textureId_up = loadTexture("assets/hw_nightsky/nightsky_up.png");
			break;
		case 24:
			textureId_bk = loadTexture("assets/mp_midnight/midnight-silence_bk.png");
			textureId_dn = loadTexture("assets/mp_midnight/midnight-silence_dn.png");
			textureId_ft = loadTexture("assets/mp_midnight/midnight-silence_ft.png");
			textureId_lf = loadTexture("assets/mp_midnight/midnight-silence_lf.png");
			textureId_rt = loadTexture("assets/mp_midnight/midnight-silence_rt.png");
			textureId_up = loadTexture("assets/mp_midnight/midnight-silence_up.png");
			break;
		default:
			break;
	}
	
	glPushMatrix();
	glTranslated(x, y , 0 );
	glRotated(angle, 0, 0, 1);
	
	glBindTexture(GL_TEXTURE_2D, textureId_bk);
	glBegin(GL_QUADS);
	
	glColor3ub(255, 255, 255); //face rouge
	glTexCoord2d(1, 1); glVertex3d(w, w, w);
	glTexCoord2d(1, 0); glVertex3d(w, w, -w);
	glTexCoord2d(1, 0); glVertex3d(-w, w, -w);
	glTexCoord2d(0, 1); glVertex3d(-w, w, w);
	
	glBindTexture(GL_TEXTURE_2D, textureId_rt);
	
	glTexCoord2d(0, 0);glVertex3d(w, -w, w);
	glTexCoord2d(0, 1);glVertex3d(w, -w, -w);
	glTexCoord2d(1, 1);glVertex3d(w, w, -w);
	glTexCoord2d(1, 0);glVertex3d(w, w, w);
	
	glBindTexture(GL_TEXTURE_2D, textureId_ft);
	glTexCoord2d(0, 0);glVertex3d(-w, -w, w);
	glTexCoord2d(0, 1);glVertex3d(-w, -w, -w);
	glTexCoord2d(1, 1);glVertex3d(w, -w, -w);
	glTexCoord2d(1, 0);glVertex3d(w, -w, w);
	
	glBindTexture(GL_TEXTURE_2D, textureId_lf);
	glTexCoord2d(0, 0);glVertex3d(-w, w, w);
	glTexCoord2d(0, 1);glVertex3d(-w, w, -w);
	glTexCoord2d(1, 1);glVertex3d(-w, -w, -w);
	glTexCoord2d(1, 0);glVertex3d(-w, -w, w);
	
	glBindTexture(GL_TEXTURE_2D, textureId_dn);
	glTexCoord2d(0, 0);glVertex3d(w, w, -w);
	glTexCoord2d(0, 1);glVertex3d(w, -w, -w);
	glTexCoord2d(1, 1);glVertex3d(-w, -w, -w);
	glTexCoord2d(1, 0);glVertex3d(-w, w, -w);
	
	glBindTexture(GL_TEXTURE_2D, textureId_up);
	glTexCoord2d(0, 0);glVertex3d(w, -w, w);
	glTexCoord2d(0, 1);glVertex3d(w, w, w);
	glTexCoord2d(1, 1);glVertex3d(-w, w, w);
	glTexCoord2d(1, 0);glVertex3d(-w, -w, w);
	
	glEnd();
	glPopMatrix();
}



void Utils::MakePlatform(float w, float h, float x, float y,float z, float angle, bool darker, bool makeFence)
{
	GLuint textureId_bk;
	int clr = 255;
	//textureId_bk = loadTexture("assets/textures/txt_platform_short.jpg");
	glBindTexture(GL_TEXTURE_2D, textureId_bk);
	glPushMatrix();
	glTranslated(x, y , z );
	glRotated(angle, 1, 0, 0);
	glBegin(GL_QUADS);
	glColor3ub(clr, clr, clr);
	glTexCoord2d(0, 0);glVertex3d(0,0, 0);
	glTexCoord2d(0, 1);glVertex3d(w, 0, 0);
	glTexCoord2d(1, 1);glVertex3d(w, w, 0);
	glTexCoord2d(1, 0);glVertex3d(0, w, 0);
	glColor3ub(clr - 50, clr - 50, clr - 50);
	glTexCoord2d(0, 0);glVertex3d(w, 0, 0);
	glTexCoord2d(0, 1);glVertex3d(w, w, 0);
	glTexCoord2d(1, 1);glVertex3d(w, w, h);
	glTexCoord2d(1, 0);glVertex3d(w, 0, h);
	glColor3ub(clr - 150, clr - 150, clr - 150);
	
	glTexCoord2d(0, 0);glVertex3d(w, 0, h);
	glTexCoord2d(0, 1);glVertex3d(0, 0, h);
	glTexCoord2d(1, 1);glVertex3d(0, 0, 0);
	glTexCoord2d(1, 0);glVertex3d(w, 0, 0);
	glColor3ub(clr, clr, clr);
	glTexCoord2d(0, 0);glVertex3d(0, 0, h);
	glTexCoord2d(0, 1);glVertex3d(0, w, h);
	glTexCoord2d(1, 1);glVertex3d(0, w, 0);
	glTexCoord2d(1, 0);glVertex3d(0, 0, 0);
	glColor3ub(clr - 150, clr - 150, clr - 150);
	glTexCoord2d(0, 0);glVertex3d(0, w, 0);
	glTexCoord2d(0, 1);glVertex3d(w, w, 0);
	glTexCoord2d(1, 1);glVertex3d(w, w, h);
	glTexCoord2d(1, 0);glVertex3d(0, w, h);
	glColor3ub(clr, clr, clr);
	
	glTexCoord2d(0, 0);glVertex3d(0, 0, h);
	glTexCoord2d(0, 1);glVertex3d(w, 0, h);
	glTexCoord2d(1, 1);glVertex3d(w, w, h);
	glTexCoord2d(1, 0);glVertex3d(0, w, h);
	if(makeFence)
	{
		glRotated(90, 1, 0, 0);
		Utils::MakeFence(0.5f, 4, w, w, h);
	}
	glEnd();
	
	glPopMatrix();
}

void Utils::MakeFenceSquare(float w, float h, float x, float y, float z)
{
	MakePlatform(w, h, x, y, z, 0, false, false);
	MakePlatform(w, h, x, y, z, 90, false, false);
	glPushMatrix();
	glTranslated(0, -h, h);
	
	MakePlatform(w, h, x, y, z, -90, false, false);
	MakePlatform(w, h, x, y, z, 180, false, false);
	glPopMatrix();
}

void Utils::MakeFence(float w, float h, float x, float y, float z )
{
	Direction dir = Direction::LEFT;
	std::vector<Direction> directions;
	int r = rand() % 9;
	for(int i = 1; i < 5; i ++) {
		
		if(i == 1){
			Utils::MakeFenceSquare(w, h, x, y, z);
		}
		else {
			switch (dir) {
				case LEFT:
					Utils::MakeFenceSquare(w, h / i, x, y, z + (h/2) / i);
					
					break;
				case TOP:
					if(r % 2 == 0) {
						Utils::MakeFenceSquare(w, h / i, x + ((h / 2)/ i), y, z + (h/i));
					}
					else{
						Utils::MakeFenceSquare(w, h / i, x, y, z + (h/i));
					}
					break;
				case RIGHT:
					Utils::MakeFenceSquare(w, h / i, x , y + (h/i), z + ((h/2)/i));
					
					break;
				case DOWN:
					if(r % 2 == 0) {
						Utils::MakeFenceSquare(w, h / i, x + (h / 2), y, z - w);
					}
					else{
						Utils::MakeFenceSquare(w, h / i, x, y, z - w);
					}
					break;
				default:
					break;
			}
			dir = Utils::ChooseDirection(dir);
		}
		r = rand() * 10;
	}
	
}

Utils::Direction Utils::ChooseDirection(Utils::Direction &lastDir)
{
	srand(time(NULL));
	int r = rand() * 3;
	Utils::Direction toRet = Utils::DOWN;
	
	switch(lastDir)
	{
		case Utils::LEFT:
			if(r == 0)
				toRet = Utils::RIGHT;
			else if(r == 1)
				toRet = Utils::TOP;
			else if(r == 2)
				toRet = Utils::DOWN;
			break;
		case Utils::TOP:
			if(r == 0)
				toRet = Utils::RIGHT;
			else if(r == 1)
				toRet = Utils::LEFT;
			else if(r == 2)
				toRet = Utils::DOWN;
			break;
		case Utils::RIGHT:
			if(r == 0)
				toRet = Utils::LEFT;
			else if(r == 1)
				toRet = Utils::TOP;
			else if(r == 2)
				toRet = Utils::DOWN;
			break;
		case Utils::DOWN:
			if(r == 0)
				toRet = Utils::RIGHT;
			else if(r == 1)
				toRet = Utils::TOP;
			else if(r == 2)
				toRet = Utils::LEFT;
			break;
		default:
			break;
	}
	return toRet;
}

const std::vector<GameObject *> &Utils::getLevel() const {
	return level;
}
