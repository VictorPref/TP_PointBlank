//
// Created by Jean-François on 12/20/2018.
//

#include "UI.h"

UI::UI(float widthScreen, float heightScreen) : widthScreen(widthScreen), heightScreen(heightScreen) {}

void UI::DrawLifeBar(float playerLife) {
    gluOrtho2D(0, widthScreen,0,heightScreen);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor4ub(255, 0, 0, 100);
    glVertex2f(0, heightScreen);
    glVertex2f(widthScreen/10, heightScreen);
    glVertex2f(widthScreen/10, heightScreen - heightScreen/4);
    glVertex2f(0, heightScreen - heightScreen/4);
    glEnd();

    glBegin(GL_QUADS);
    glColor4ub(0, 255, 0, 255);
    glVertex3f(0, heightScreen,1);
    glVertex3f(widthScreen/10, heightScreen,1);
    glVertex3f(widthScreen/10, heightScreen - playerLife*heightScreen/4,1);
    glVertex3f(0, heightScreen - playerLife*heightScreen/4,1);
    glEnd();
}

void UI::DrawIsDiyingEffect() {

    gluOrtho2D(0, widthScreen,0,heightScreen);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor4ub(255, 0, 0, 95);
    glVertex2f(0, heightScreen);
    glVertex2f(widthScreen, heightScreen);
    glVertex2f(widthScreen, 0);
    glVertex2f(0, 0);
    glEnd();
}

void UI::DrawTargetCross() {

    gluOrtho2D(0, widthScreen,0,heightScreen);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_LINES);
    glColor4ub(255, 0, 0, 255);
    glVertex3i(widthScreen/2.05,heightScreen/2,1);
    glVertex3i(widthScreen/1.95,heightScreen/2,1);
    glVertex3i(widthScreen/2,heightScreen/1.9,1);
    glVertex3i(widthScreen/2,heightScreen/2.1,1);
    glEnd();

}

void UI::DrawUI(float playerLife) {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    DrawLifeBar(playerLife);
    if(playerLife >0 && playerLife <0.25)
        DrawIsDiyingEffect();
    DrawTargetCross();
}