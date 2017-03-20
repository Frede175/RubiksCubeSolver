// RubiksCubeSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>
#include "node.h"
#include "tree.h"
#include <stdlib.h> 


RubikCube_T cube = { 
	{
		{ //Front
			{ RubikColor_T::ORANGE, RubikColor_T::BLUE, RubikColor_T::BLUE },
			{ RubikColor_T::ORANGE, RubikColor_T::ORANGE, RubikColor_T::YELLOW },
			{ RubikColor_T::ORANGE, RubikColor_T::GREEN, RubikColor_T::GREEN }
		},
		{ //BACK
			{ RubikColor_T::RED, RubikColor_T::RED, RubikColor_T::RED },
			{ RubikColor_T::WHITE, RubikColor_T::RED, RubikColor_T::RED },
			{ RubikColor_T::GREEN, RubikColor_T::WHITE, RubikColor_T::BLUE }
		},
		{ //LEFT
			{ RubikColor_T::GREEN, RubikColor_T::BLUE, RubikColor_T::YELLOW },
			{ RubikColor_T::GREEN, RubikColor_T::GREEN, RubikColor_T::GREEN },
			{ RubikColor_T::RED, RubikColor_T::RED, RubikColor_T::YELLOW }
		},
		{ //RIGHT
			{ RubikColor_T::WHITE, RubikColor_T::WHITE, RubikColor_T::BLUE },
			{ RubikColor_T::ORANGE, RubikColor_T::BLUE, RubikColor_T::ORANGE },
			{ RubikColor_T::YELLOW, RubikColor_T::BLUE, RubikColor_T::ORANGE }
		},
		{ //TOP
			{ RubikColor_T::WHITE, RubikColor_T::WHITE, RubikColor_T::WHITE },
			{ RubikColor_T::YELLOW, RubikColor_T::WHITE, RubikColor_T::GREEN },
			{ RubikColor_T::GREEN, RubikColor_T::ORANGE, RubikColor_T::ORANGE }
		},
		{ //BOTTOM
			{ RubikColor_T::BLUE, RubikColor_T::YELLOW, RubikColor_T::RED },
			{ RubikColor_T::YELLOW, RubikColor_T::YELLOW, RubikColor_T::RED },
			{ RubikColor_T::YELLOW, RubikColor_T::BLUE, RubikColor_T::WHITE }
		}
	} 
};


int main()
{

	node * _node = new node(nullptr, nullptr, cube, 1);
	tree * _tree = new tree(_node);

	std::vector<RubikAction_T> actions;

	auto begin = std::chrono::steady_clock::now();

	_tree->findSolution(&actions);

	auto end = std::chrono::steady_clock::now();

	std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms" << "\n";

	for (std::vector<RubikAction_T>::iterator i = actions.begin(); i != actions.end(); ++i)
		std::cout << RubikRotationChar[(*i).action] << RubikRotationsChar[(*i).rotations-1] << ' ';


	RubiksHelper::printCube(&cube);
    return 0;
}

