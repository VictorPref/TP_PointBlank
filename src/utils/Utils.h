//
// Created by cchevret on 2018-12-12.
//

#ifndef OPENGLTEST1_UTILS_H
#define OPENGLTEST1_UTILS_H


class Utils {
public:
	enum Direction { LEFT, TOP, RIGHT, DOWN};
	static void MakeWhiteSquare(float w, float h, float x, float y, float angle, bool darker);
	static void MakePlatform(float w, float h, float x, float y, float z, float angle, bool darker, bool makeFence);
	static void MakeFence(float w, float h, float x, float y, float z );
	static void MakeFenceSquare(float w, float h, float x, float y, float z);
	static Direction ChooseDirection(Direction &lastDir);
	static void MakeSkybox(int timeOfDay, float w, float x, float y, float angle);
	static void GenerateWorld(int timeOfDay);
};


#endif //OPENGLTEST1_UTILS_H
