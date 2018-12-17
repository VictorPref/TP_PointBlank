//
// Created by prefo on 2018-12-17.
//

#include "Texture.h"


Texture::Texture() {}

GLuint Texture::getIdTexture() const {
    return idTexture;
}

void Texture::setIdTexture(GLuint idTexture) {
    Texture::idTexture = idTexture;
}

int Texture::getDivisionTexture() const {
    return divisionTexture;
}

void Texture::setDivisionTexture(int divisionTexture) {
    Texture::divisionTexture = divisionTexture;
}

Texture::Texture(GLuint idTexture, int divisionTexture) : idTexture(idTexture), divisionTexture(divisionTexture) {}

Texture::~Texture() {
    glDeleteTextures(1, &idTexture);
}
