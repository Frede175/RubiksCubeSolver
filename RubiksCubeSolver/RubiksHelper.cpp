#include "stdafx.h"
#include "RubiksHelper.h"

namespace RubiksHelper {

	void rotateCube(RubikCube_T * cube, RubikRotation_T action, uint8_t rotations) {
		if (rotations == -1) rotations = 3;
		switch (action)
		{
		case RubikRotation_T::LEFT:
		{
			//Face rotation:
			rotateFace(cube, rotations, RubikSide_T::SIDE_LEFT);
			//Side rotation:
			uint8_t order[4] = { RubikSide_T::SIDE_FRONT, RubikSide_T::SIDE_BOTTOM, RubikSide_T::SIDE_BACK, RubikSide_T::SIDE_TOP};
			for (int r = 0; r < rotations; r++) {
				uint8_t side[3] = { cube->cube[order[3]][0][0],cube->cube[order[3]][1][0],cube->cube[order[3]][2][0] };

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 3; j++) {
						uint8_t temp = side[j];
						side[j] = cube->cube[order[i]][j][0];
						cube->cube[order[i]][j][0] = temp;
					}
				}
			}
			
		}
			break;
		case RubikRotation_T::RIGHT:
		{
			rotateFace(cube, rotations, RubikSide_T::SIDE_RIGHT);

			//Side rotation:
			uint8_t order[4] = { RubikSide_T::SIDE_FRONT, RubikSide_T::SIDE_TOP, RubikSide_T::SIDE_BACK, RubikSide_T::SIDE_BOTTOM };
			for (int r = 0; r < rotations; r++) {
				uint8_t side[3] = { cube->cube[order[3]][0][2],cube->cube[order[3]][1][2],cube->cube[order[3]][2][2] };

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 3; j++) {
						uint8_t temp = side[j];
						side[j] = cube->cube[order[i]][j][2];
						cube->cube[order[i]][j][2] = temp;
					}
				}
			}
		}
			break;
		case RubikRotation_T::FRONT:
		{
			//Face rotation:
			rotateFace(cube, rotations, RubikSide_T::SIDE_FRONT);
			//Side rotation:
			uint8_t order[4] = { RubikSide_T::SIDE_LEFT, RubikSide_T::SIDE_TOP, RubikSide_T::SIDE_RIGHT, RubikSide_T::SIDE_BOTTOM };
			for (int r = 0; r < rotations; r++) {
				uint8_t side[3] = { cube->cube[order[3]][0][0],cube->cube[order[3]][0][1],cube->cube[order[3]][0][2] };

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 3; j++) {
						uint8_t temp = side[j];

						if (i == 0) {
							side[j] = cube->cube[order[i]][j][2];
							cube->cube[order[i]][j][2] = temp;
						} else if (i == 1) {
							side[j] = cube->cube[order[i]][2][2-j];
							cube->cube[order[i]][2][2-j] = temp;
						} else if (i == 2) {
							side[j] = cube->cube[order[i]][2-j][0];
							cube->cube[order[i]][2-j][0] = temp;
						} else if (i == 3) {
							side[j] = cube->cube[order[i]][0][j];
							cube->cube[order[i]][0][j] = temp;
						}
					}
				}
			}

		}
			break;
		case RubikRotation_T::BACK:
		{
			//Face rotation:
			rotateFace(cube, rotations, RubikSide_T::SIDE_BACK);
			//Side rotation:
			uint8_t order[4] = { RubikSide_T::SIDE_LEFT, RubikSide_T::SIDE_BOTTOM, RubikSide_T::SIDE_RIGHT, RubikSide_T::SIDE_TOP };
			for (int r = 0; r < rotations; r++) {
				uint8_t side[3] = { cube->cube[order[3]][0][0],cube->cube[order[3]][0][1],cube->cube[order[3]][0][2] };

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 3; j++) {
						uint8_t temp = side[j];

						if (i == 0) {
							side[j] = cube->cube[order[i]][2 - j][0];
							cube->cube[order[i]][2 - j][0] = temp;
						}
						else if (i == 1) {
							side[j] = cube->cube[order[i]][2][2 - j];
							cube->cube[order[i]][2][2 - j] = temp;
						}
						else if (i == 2) {
							side[j] = cube->cube[order[i]][j][2];
							cube->cube[order[i]][j][2] = temp;
						}
						else if (i == 3) {
							side[j] = cube->cube[order[i]][0][j];
							cube->cube[order[i]][0][j] = temp;
						}
					}
				}
			}

		}
			break;
		case RubikRotation_T::UP:
		{
			//Face rotation:
			rotateFace(cube, rotations, RubikSide_T::SIDE_TOP);
			//Side rotation:
			uint8_t order[4] = { RubikSide_T::SIDE_FRONT, RubikSide_T::SIDE_LEFT, RubikSide_T::SIDE_BACK, RubikSide_T::SIDE_RIGHT };
			for (int r = 0; r < rotations; r++) {
				uint8_t side[3] = { cube->cube[order[3]][0][0],cube->cube[order[3]][1][0],cube->cube[order[3]][2][0] };

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 3; j++) {
						uint8_t temp = side[j];
						side[j] = cube->cube[order[i]][j][0];
						cube->cube[order[i]][j][0] = temp;
					}
				}
			}

		}
			break;
		case RubikRotation_T::DOWN:
		{
			//Face rotation:
			rotateFace(cube, rotations, RubikSide_T::SIDE_TOP);
			//Side rotation:
			uint8_t order[4] = { RubikSide_T::SIDE_FRONT, RubikSide_T::SIDE_RIGHT, RubikSide_T::SIDE_BACK, RubikSide_T::SIDE_LEFT };
			for (int r = 0; r < rotations; r++) {
				uint8_t side[3] = { cube->cube[order[3]][2][0],cube->cube[order[3]][2][1],cube->cube[order[3]][2][2] };

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 3; j++) {
						uint8_t temp = side[j];
						side[j] = cube->cube[order[i]][2][j];
						cube->cube[order[i]][2][j] = temp;
					}
				}
			}

		}
			break;
		case RubikRotation_T::MIDDEL:
		{
			//Side rotation:
			uint8_t order[4] = { RubikSide_T::SIDE_FRONT, RubikSide_T::SIDE_BOTTOM, RubikSide_T::SIDE_BACK, RubikSide_T::SIDE_TOP };
			for (int r = 0; r < rotations; r++) {
				uint8_t side[3] = { cube->cube[order[3]][0][1],cube->cube[order[3]][1][1],cube->cube[order[3]][2][1] };

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 3; j++) {
						uint8_t temp = side[j];
						side[j] = cube->cube[order[i]][j][1];
						cube->cube[order[i]][j][1] = temp;
					}
				}
			}

		}
			break;
		case RubikRotation_T::EQUATOR:
		{
			//Face rotation:
			rotateFace(cube, rotations, RubikSide_T::SIDE_TOP);
			//Side rotation:
			uint8_t order[4] = { RubikSide_T::SIDE_FRONT, RubikSide_T::SIDE_RIGHT, RubikSide_T::SIDE_BACK, RubikSide_T::SIDE_LEFT };
			for (int r = 0; r < rotations; r++) {
				uint8_t side[3] = { cube->cube[order[3]][1][0],cube->cube[order[3]][1][1],cube->cube[order[3]][1][2] };

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 3; j++) {
						uint8_t temp = side[j];
						side[j] = cube->cube[order[i]][1][j];
						cube->cube[order[i]][1][j] = temp;
					}
				}
			}

		}
			break;
		case RubikRotation_T::STANDING:
		{
			//Side rotation:
			uint8_t order[4] = { RubikSide_T::SIDE_LEFT, RubikSide_T::SIDE_TOP, RubikSide_T::SIDE_RIGHT, RubikSide_T::SIDE_BOTTOM };
			for (int r = 0; r < rotations; r++) {
				uint8_t side[3] = { cube->cube[order[3]][1][0],cube->cube[order[3]][1][1],cube->cube[order[3]][1][2] };

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 3; j++) {
						uint8_t temp = side[j];

						if (i == 0) {
							side[j] = cube->cube[order[i]][j][1];
							cube->cube[order[i]][j][1] = temp;
						}
						else if (i == 1) {
							side[j] = cube->cube[order[i]][1][2 - j];
							cube->cube[order[i]][1][2 - j] = temp;
						}
						else if (i == 2) {
							side[j] = cube->cube[order[i]][2 - j][1];
							cube->cube[order[i]][2 - j][1] = temp;
						}
						else if (i == 3) {
							side[j] = cube->cube[order[i]][1][j];
							cube->cube[order[i]][1][j] = temp;
						}
					}
				}
			}

		}
			break;
		}

		

	}
	void printCube(RubikCube_T * cube)
	{
		for (int i = 0; i < 6; i++) {
			std::cout << EnumStrings[i] << "\n";

			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					std::cout << unsigned(cube->cube[i][y][x]) << " ";
				}

				std::cout << "\n";
			}
		}
	}

	void rotateFace(RubikCube_T * cube, uint8_t rotations, RubikSide_T side)
	{
		uint8_t face[3][3];
		for (uint8_t x = 0; x < 3; x++) {
			for (uint8_t y = 0; y < 3; y++) {
				if (rotations == 1) face[y][x] = cube->cube[side][2 - x][y];
				else if (rotations == 2) face[y][x] = cube->cube[side][2 - x][2 - y];
				else if (rotations == 3) face[y][x] = cube->cube[side][x][2 - y];
			}
		}
		for (uint8_t x = 0; x < 3; x++) {
			for (uint8_t y = 0; y < 3; y++) {
				cube->cube[side][x][y] = face[x][y];
			}
		}
	}


	bool isSolved(RubikCube_T * cube)
	{
		for (int f = 0; f < 6; f++) { //FACES
			uint8_t middel = cube->cube[f][1][1];
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					if (middel != cube->cube[f][y][x]) return false;
				}
			}
		}
		return true;
	}
}


