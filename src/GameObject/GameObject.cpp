//
// Created by prefo on 2018-12-17.
//

#include "GameObject.h"
#include "../utils/sdlglutils.h"
int GameObject::listSave = 1;
Vector3 &GameObject::getTransform() {
    return transform;
}

void GameObject::setTransform(const Vector3 &transform) {
    GameObject::transform = transform;
}

const Vector3 &GameObject::getScale() const {
    return scale;
}

void GameObject::setScale(const Vector3 &scale) {
    GameObject::scale = scale;
}

const Vector3 &GameObject::getRotation() const {
    return rotation;
}

void GameObject::setRotation(const Vector3 &rotation) {
    GameObject::rotation = rotation;
}

const Vector3 &GameObject::getColor() const {
    return color;
}

void GameObject::setColor(const Vector3 &color) {
    GameObject::color = color;
}

const std::string &GameObject::getPathTexture() const {
    return pathTexture;
}

void GameObject::setPathTexture(const std::string &pathTexture) {
    GameObject::pathTexture = pathTexture;
}

GameObject::GameObject(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation,
                       const std::string &pathTexture,int divisionTexture) : transform(transform), scale(scale), rotation(rotation),
                                                         pathTexture(pathTexture) {


    setBasicTransform(transform,scale,rotation);

    GLuint idText = loadTexture(pathTexture.c_str());
    texture.setIdTexture(idText);
    texture.setDivisionTexture(divisionTexture);

    Vector3 c (255,255,255);
    color = c;



}

GameObject::GameObject(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color)
        : transform(transform), scale(scale), rotation(rotation), color(color) {

    setBasicTransform(transform,scale,rotation);

    this->color = color;

}

void GameObject::setBasicTransform(Vector3 trans, Vector3 sc, Vector3 rot) {

    transform = trans;
    scale = sc;
    rotation = rot;

}

void GameObject::draw() {

    glPushMatrix();
    glTranslated(transform.getX(),transform.getY(),transform.getZ());
    glRotated(rotation.getX(),1,0,1);
    glRotated(rotation.getY(),0,1,0);
    glRotated(rotation.getZ(),0,0,1);

    glCallList(idGameObject);

    glPopMatrix();

}

GameObject::~GameObject() {

    glDeleteLists(idGameObject, 1);
}



