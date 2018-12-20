
#include <GL/gl.h>
#include <GL/glu.h>
#include "../GameObject/Component/Vector3.h"

class Camera {

private:
    float angleZRotationCamera = 0;
    float angleXRotationCamera = 0;
    int angleMaxView = 30;
    Vector3* playerTransform;

public:
    Camera();

    Camera(Vector3& transform);

    void LookLeft();
    void LookRight();
    void LookUp();
    void LookDown();

    void Look();
    void Update();

    Camera(Vector3 *playerTransform);
};

