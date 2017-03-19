#pragma once


#ifndef node_h
#define node_h

#include <stdint.h>
#include <vector>


//Node the rubiks data
class node {
public:
	node(node * parrent, RubikAction_T * lastAction, RubikCube_T cube, uint8_t depth);
	node(const node& other);
	void addNode(node * _node);
	RubikCube_T getData();
	RubikAction_T * getLastAction();
	node * getParrent();
	uint8_t getDepth();
	~node();
private:
	uint8_t depth;
	node * parrent;
	RubikAction_T * lastAction;
	RubikCube_T cube;
	std::vector<node> nodes;
};

#endif // !node_h
