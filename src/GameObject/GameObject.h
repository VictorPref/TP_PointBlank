//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_GAMEOBJECT_H
#define TP_POINTBLANK_GAMEOBJECT_H

#include "Component/Vector3.h"
#include "Component/Texture.h"
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "string"
#include "vector"

class GameObject {

protected:
    Vector3 transform;
    Vector3 scale;
    Vector3 rotation;
    Vector3 color;
    Texture texture;

    GLuint idGameObject;
    std::string pathTexture;


public:

    GameObject(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const std::string &pathTexture,int divisionTexture);

    GameObject(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color);

    void setBasicTransform(Vector3 trans,Vector3 sc,Vector3 rot);

    virtual ~GameObject();

    const Vector3 &getTransform() const;

    void setTransform(const Vector3 &transform);

    const Vector3 &getScale() const;

    void setScale(const Vector3 &scale);

    const Vector3 &getRotation() const;

    void setRotation(const Vector3 &rotation);

    const Vector3 &getColor() const;

    void setColor(const Vector3 &color);

    const std::string &getPathTexture() const;

    void setPathTexture(const std::string &pathTexture);
    void draw();


};


#endif //TP_POINTBLANK_GAMEOBJECT_H
