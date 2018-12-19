
#include <GL/gl.h>
#include <GL/glu.h>

class Camera {

private:
    float angleZRotationCamera = 0;
    float angleXRotationCamera = 0;
    int angleMaxView = 30;
    float positionXPlayer, positionYPlayer, positionZPlayer;

public:
    Camera();

    Camera(float positionXPlayer, float positionYPlayer, float positionZPlayer);

    void LookLeft();
    void LookRight();
    void LookUp();
    void LookDown();

    void Look();

};

