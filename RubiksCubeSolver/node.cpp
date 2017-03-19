#include "stdafx.h"
#include "node.h"


node::node(node * parrent, RubikAction_T * lastAction, RubikCube_T cube, uint8_t depth) {
	this->parrent = parrent;
	this->lastAction = lastAction;
	this->cube = cube;
	this->depth = depth;
}

node::node(const node & other) {
	this->cube = other.cube;
	this->lastAction = other.lastAction;
	this->nodes = other.nodes;
	this->parrent = other.parrent;
}

void node::addNode(node * _node) {
	nodes.push_back((*_node));
}

RubikCube_T node::getData() {
	return cube;
}

RubikAction_T * node::getLastAction()
{
	return lastAction;
}

node * node::getParrent()
{
	return parrent;
}

uint8_t node::getDepth()
{
	return depth;
}

node::~node() {
	for (std::vector<node>::iterator it = nodes.begin(); it < nodes.end(); it++) {
		delete &it;
	}
}