
class Camera {

private:
    float angleZRotationCamera = 0;
    float angleXRotationCamera = 0;
    int angleMaxView = 30;

public:
    Camera();

    void LookLeft();
    void LookRight();
    void LookUp();
    void LookDown();

};

