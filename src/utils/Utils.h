//
// Created by cchevret on 2018-12-12.
//

#ifndef OPENGLTEST1_UTILS_H
#define OPENGLTEST1_UTILS_H

#include "../GameObject/GameObject.h"
class Utils {

	static std::vector<GameObject*> level;
public:
	enum Direction { LEFT, TOP, RIGHT, DOWN};
	static void MakeWhiteSquare(float w, float h, float x, float y, float angle, bool darker);
	static void MakePlatform(float w, float h, float x, float y, float z, float angle, bool darker, bool makeFence);
	static void MakeFence(float w, float h, float x, float y, float z );
	static void MakeFenceSquare(float w, float h, float x, float y, float z);
	static Direction ChooseDirection(Direction &lastDir);
	static void MakeSkybox(int timeOfDay, float w, float x, float y, float angle);
	static void GenerateWorld(int timeOfDay);

	const std::vector<GameObject *> &getLevel() const;


};


#endif //OPENGLTEST1_UTILS_H
