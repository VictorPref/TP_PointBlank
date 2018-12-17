//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_TEXTURE_H
#define TP_POINTBLANK_TEXTURE_H
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Texture {

    GLuint idTexture;
    int divisionTexture;

public:

    Texture();

    Texture(GLuint idTexture, int divisionTexture);

    virtual ~Texture();

    GLuint getIdTexture() const;

    void setIdTexture(GLuint idTexture);

    int getDivisionTexture() const;

    void setDivisionTexture(int divisionTexture);


};


#endif //TP_POINTBLANK_TEXTURE_H
