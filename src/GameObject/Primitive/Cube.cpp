//
// Created by prefo on 2018-12-17.
//

#include "Cube.h"

Cube::Cube(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color) : GameObject(
        transform, scale, rotation, color) {



    idGameObject = glGenLists(1);
    glNewList(idGameObject, GL_COMPILE);
    glBegin(GL_QUADS);
    glColor3f(color.getX(), 0, 0);
    glVertex3d(0, 0, 0);
    glVertex3d(scale.getX(), 0, 0);
    glVertex3d(scale.getX(), scale.getY(), 0);
    glVertex3d(0, scale.getY(), 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, color.getY(), 0);
    glVertex3d(0, 0, 0);
    glVertex3d(scale.getX(), 0, 0);
    glVertex3d(scale.getX(), 0, scale.getZ());
    glVertex3d(0, 0, scale.getZ());
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3d(scale.getX(), 0, 0);
    glVertex3d(scale.getX(), 0, scale.getZ());
    glVertex3d(scale.getX(), scale.getY(), scale.getZ());
    glVertex3d(scale.getX(), scale.getY(), 0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(color.getX(), 0, color.getZ());
    glVertex3d(0, 0, 0);
    glVertex3d(0, scale.getY(), 0);
    glVertex3d(0, scale.getY(), scale.getZ());
    glVertex3d(0, 0, scale.getZ());
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, color.getZ());
    glVertex3d(0, scale.getY(), 0);
    glVertex3d(scale.getX(), scale.getY(), 0);
    glVertex3d(scale.getX(), scale.getY(), scale.getZ());
    glVertex3d(0, scale.getY(), scale.getZ());
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, color.getZ());
    glVertex3d(0, 0, scale.getZ());
    glVertex3d(scale.getX(), 0, scale.getZ());
    glVertex3d(scale.getX(), scale.getY(), scale.getZ());
    glVertex3d(0, scale.getY(), scale.getZ());
    glEnd();

    glEndList();

}

Cube::Cube(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const std::string &pathTexture,
           int divisionTexture) : GameObject(transform, scale, rotation, pathTexture, divisionTexture) {



    idGameObject = glGenLists(1);
    glNewList(idGameObject, GL_COMPILE);

    glBindTexture(GL_TEXTURE_2D, texture.getIdTexture());
    glBegin(GL_QUADS);
    glColor3f(color.getX(),color.getY(),color.getZ());
    glTexCoord2d(0,0);glVertex3d(0, 0, 0);
    glTexCoord2d(divisionTexture,0);glVertex3d(scale.getX(), 0, 0);
    glTexCoord2d(divisionTexture,divisionTexture);glVertex3d(scale.getX(), -scale.getY(), 0);
    glTexCoord2d(0,divisionTexture);glVertex3d(0, -scale.getY(), 0);
    glEnd();


    glBegin(GL_QUADS);
    glTexCoord2d(0,0);glVertex3d(0, 0, 0);
    glTexCoord2d(divisionTexture,0);glVertex3d(scale.getX(), 0, 0);
    glTexCoord2d(divisionTexture,divisionTexture);glVertex3d(scale.getX(), 0, scale.getZ());
    glTexCoord2d(0,divisionTexture);glVertex3d(0, 0, scale.getZ());
    glEnd();


    glBegin(GL_QUADS);
    glTexCoord2d(0,0); glVertex3d(scale.getX(), 0, 0);
    glTexCoord2d(divisionTexture,0); glVertex3d(scale.getX(), 0, scale.getZ());
    glTexCoord2d(divisionTexture,divisionTexture);glVertex3d(scale.getX(), -scale.getY(), scale.getZ());
    glTexCoord2d(0,divisionTexture);glVertex3d(scale.getX(), -scale.getY(), 0);

    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0,0);glVertex3d(0, 0, 0);
    glTexCoord2d(divisionTexture,0); glVertex3d(0, -scale.getY(), 0);
    glTexCoord2d(divisionTexture,divisionTexture); glVertex3d(0, -scale.getY(), scale.getZ());
    glTexCoord2d(0,divisionTexture);glVertex3d(0, 0, scale.getZ());
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0,0); glVertex3d(0, -scale.getY(), 0);
    glTexCoord2d(divisionTexture,0);glVertex3d(scale.getX(), -scale.getY(), 0);
    glTexCoord2d(divisionTexture,divisionTexture);glVertex3d(scale.getX(), -scale.getY(), scale.getZ());
    glTexCoord2d(0,divisionTexture);glVertex3d(0, -scale.getY(), scale.getZ());
    glEnd();


    glBegin(GL_QUADS);
    glTexCoord2d(0,0);glVertex3d(0, 0, scale.getZ());
    glTexCoord2d(divisionTexture,0);glVertex3d(scale.getX(), 0, scale.getZ());
    glTexCoord2d(divisionTexture,divisionTexture); glVertex3d(scale.getX(), -scale.getY(), scale.getZ());
    glTexCoord2d(0,divisionTexture);glVertex3d(0, -scale.getY(), scale.getZ());
    glEnd();
    glEndList();




}
