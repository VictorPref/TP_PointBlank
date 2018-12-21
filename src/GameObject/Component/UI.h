//
// Created by Jean-François on 12/20/2018.
//

#ifndef TP_POINTBLANK_UI_H
#define TP_POINTBLANK_UI_H

#include <GL/gl.h>
#include <GL/glu.h>

class UI {

private:
    float widthScreen, heightScreen;
    void DrawLifeBar(float playerLife);
    void DrawIsDiyingEffect();
    void DrawTargetCross();

public:
    UI(float widthScreen, float heightScreen);

    void DrawUI(float playerLife);
};


#endif //TP_POINTBLANK_UI_H
