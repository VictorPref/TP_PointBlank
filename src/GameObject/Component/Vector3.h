//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_VECTOR3_H
#define TP_POINTBLANK_VECTOR3_H


class Vector3 {

    double x,y,z;

public:
    Vector3();

    Vector3(double x, double y, double z);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getZ() const;

    void setZ(double z);

    Vector3 operator-(Vector3 b);
    Vector3 operator+(Vector3 b);

    static Vector3 Max(Vector3 a,Vector3 b);

};


#endif //TP_POINTBLANK_VECTOR3_H
