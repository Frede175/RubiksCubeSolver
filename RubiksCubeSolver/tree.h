#pragma once

#ifndef tree_h
#define tree_h

#include <queue>
#include <vector>
#include "node.h"
#include <algorithm>

class tree {
public:
	tree(node * startNode);
	void findSolution(std::vector<RubikAction_T> * outArray);
private:
	node * processNode(node * currentNode);
	std::queue<node*> stack;
	std::vector<std::string> cubes;
};

#endif // !tree_h
