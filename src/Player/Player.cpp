//
// Created by prefo on 2018-12-17.
//

#include "Player.h"
#include "../Manager/InputManager.h"


void Player::Update(std::vector<GameObject*> level) {

    std::vector<GameObject *> collision;

    input = InputManager::getInstance()->GetKeysInput(controller);

    for (int i = 0; i < level.size(); i++) {
        GameObject *go = level[i];
        if (AABB::TestCollision(this, go)) {

            collision.push_back(go);

        }
    }


    Vector3 direction(0, 0, 0);

    camera.Look(transform);

    if(input.rt){
        bulletManager->CreateBullet(this);
    }


    if(input.leftRightCam == 1){
        camera.LookRight();
        rotation.setZ(rotation.getZ()-1);
    }
    if(input.leftRightCam == -1){
        camera.LookLeft();
        rotation.setZ(rotation.getZ()+1);
    }
    if(input.upDownCam == -1){
        camera.LookUp();
        if(rotation.getX() < 30) {
          //  rotation.setX(rotation.getX() + 1);
        }
    }
    if(input.upDownCam == 1){
        camera.LookDown();
        if(rotation.getX() > -30) {
           // rotation.setX(rotation.getX() - 1);
        }
    }

    if(input.A){
        transform.setZ(transform.getZ()+40);
    }

    if (collision.size() > 0) {

        if (canFall(collision)) {
            direction.setZ(-1);
        } else if (canJump(collision)) {
            //   direction.setZ(1);
        }

        if (input.leftRightDir == -1) {
            //Bouger Droite
            Vector3 oldPos = transform;
            transform = MoveRight();
            canMove(collision,oldPos);

        } else if (input.leftRightDir == 1) {
            //Bouger Gauche
            Vector3 oldPos = transform;
            transform = MoveLeft();
            canMove(collision,oldPos);
        }


        if (input.upDownDir == 1) {
            //Bouger Haut
            Vector3 oldPos = transform;
            transform =  MoveForward();
            canMove(collision,oldPos);


        } else if (input.upDownDir == -1) {
            //Bouger Bas
            Vector3 oldPos = transform;
            transform =  MoveBackward();
            canMove(collision,oldPos);

        }
    }
    else {
            direction.setZ(-1);
        }

        transform = transform + direction;
}

bool Player::canJump(std::vector<GameObject *> collision) {

    for(int i = 0 ; i < collision.size();i++){

        int z = collision[i]->getTransform().getZ() ;

        if(z >=  transform.getZ() + scale.getZ()){
            return false;
        }

    }

    return true;
}

bool Player::canFall(std::vector<GameObject *> collision) {


    for(int i = 0 ; i < collision.size();i++){

        int z = collision[i]->getTransform().getZ() + collision[i]->getScale().getZ();

        if(z <=  transform.getZ()){
            transform.setZ(z);
            return false;
        }

    }

    return true;
}

Vector3 Player::MoveForward()
{
    double x = transform.getX();
    double y = transform.getY();
    double angle = rotation.getZ();

    x -= vitesse * sinf(angle * 3.1416 /180);
    y += vitesse *cosf(angle * 3.1416 /180);

    return Vector3(x,y,transform.getZ());
}

Vector3 Player::MoveBackward()
{
    double x = transform.getX();
    double y = transform.getY();
    double angle = rotation.getZ();

    x += vitesse * sinf(angle * 3.1416 /180);
    y -= vitesse *cosf(angle * 3.1416 /180);

    return Vector3(x,y,transform.getZ());
}

Vector3 Player::MoveLeft()
{
    double x = transform.getX();
    double y = transform.getY();
    double angle = rotation.getZ();
    x -= vitesse * sinf((angle-90) * 3.1416 /180);
    y += vitesse *cosf((angle-90) * 3.1416 /180);

    return Vector3(x,y,transform.getZ());

}

Vector3 Player::MoveRight()
{
    double x = transform.getX();
    double y = transform.getY();
    double angle = rotation.getZ();

    x -= vitesse * sinf((angle+90) * 3.1416 /180);
    y += vitesse *cosf((angle+90) * 3.1416 /180);

    return Vector3(x,y,transform.getZ());
}

void Player::setController(SDL_Joystick *controller) {
    this->controller = controller;
}

void Player::canMove(std::vector<GameObject*> collision,Vector3 oldPos) {


    bool canMove = true;
    for(int i =0;i< collision.size();i++) {

        int z = collision[i]->getTransform().getZ() + collision[i]->getScale().getZ();

        if(z > transform.getZ()) {
            if (AABB::TestCollision(this, collision[i])) {
                std::cout<<"Can't move"<<std::endl;
                canMove = false;
            }
        }
    }

    if(!canMove) {
        transform = oldPos;
    }


}


int Player::getId() const {
    return id;
}

Player::Player(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color, int id)
        : Cube(transform, scale, rotation, color), id(id) {

    bulletManager = BulletManager::getInstance();

    camera = {transform};

    ui = new UI(1920,1080);
}

Player::Player(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const std::string &pathTexture,
               int divisionTexture, int id) : Cube(transform, scale, rotation, pathTexture, divisionTexture), id(id) {


    bulletManager = BulletManager::getInstance();

    ui = new UI(1920,1080);
}

 Camera &Player::getCamera() {
    return camera;
}

UI *Player::getUi() const {
    return ui;
}

float Player::getHealth() const {
    return health;
}


