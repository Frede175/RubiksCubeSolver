#pragma once

#ifndef RubiksHelper_h
#define RubiksHelper_h
#include <iostream>
#include <stdint.h>
#include <string>


struct RubikCube_T {
	uint8_t cube[6][3][3]; //FACE, Y, X

	friend bool operator ==(const RubikCube_T & c1, const RubikCube_T & c2) {
		std::cout << "Called";
		for (int f = 0; f < 6; f++) {
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					if (c1.cube[f][y][x] != c2.cube[f][y][x]) return false;
				}
			}
		}

		return true;
	}


} ;



static const char * EnumStrings[] = { "FRONT", "BACK", "LEFT", "RIGHT", "TOP", "BOTTOM" };


typedef enum  {
	SIDE_FRONT = 0,
	SIDE_BACK,
	SIDE_LEFT,
	SIDE_RIGHT,
	SIDE_TOP,
	SIDE_BOTTOM
} RubikSide_T;


typedef enum {
	GREEN = 0,
	YELLOW,
	BLUE,
	RED,
	WHITE,
	ORANGE
} RubikColor_T;

typedef enum  {
	LEFT = 0,
	RIGHT,
	FRONT,
	BACK,
	UP,
	DOWN,
	MIDDEL,
	EQUATOR,
	STANDING
} RubikRotation_T;

static const char * RubikRotationChar[] = {"L", "R", "F", "B", "U", "D", "M", "E", "S"};
static const char * RubikRotationsChar[] = { "0", "2", "'" };

typedef struct {
	RubikRotation_T action;
	uint8_t rotations;
} RubikAction_T;

static RubikAction_T Actions[18] = {
	{ RubikRotation_T::LEFT, 1 },
	{ RubikRotation_T::LEFT, 2 },
	{ RubikRotation_T::LEFT, 3 },
	{ RubikRotation_T::RIGHT, 1 },
	{ RubikRotation_T::RIGHT, 2 },
	{ RubikRotation_T::RIGHT, 3 },
	{ RubikRotation_T::FRONT, 1 },
	{ RubikRotation_T::FRONT, 2 },
	{ RubikRotation_T::FRONT, 3 },
	{ RubikRotation_T::BACK, 1 },
	{ RubikRotation_T::BACK, 2 },
	{ RubikRotation_T::BACK, 3 },
	{ RubikRotation_T::UP, 1 },
	{ RubikRotation_T::UP, 2 },
	{ RubikRotation_T::UP, 3 },
	{ RubikRotation_T::DOWN, 1 },
	{ RubikRotation_T::DOWN, 2 },
	{ RubikRotation_T::DOWN, 3 }
	/*{ RubikRotation_T::MIDDEL, 1 },
	{ RubikRotation_T::MIDDEL, 2 },
	{ RubikRotation_T::MIDDEL, 3 },
	{ RubikRotation_T::EQUATOR, 1 },
	{ RubikRotation_T::EQUATOR, 2 },
	{ RubikRotation_T::EQUATOR, 3 },
	{ RubikRotation_T::STANDING, 1 },
	{ RubikRotation_T::STANDING, 2 },
	{ RubikRotation_T::STANDING, 3 }*/
};


namespace RubiksHelper {
	void rotateCube(RubikCube_T * cube, RubikRotation_T action, uint8_t rotations);
	void printCube(RubikCube_T * cube);
	
	void rotateFace(RubikCube_T * cube, uint8_t rotations, RubikSide_T side);

	bool isSolved(RubikCube_T * cube);

	std::string convertToNumber(RubikCube_T * cube);
}


#endif