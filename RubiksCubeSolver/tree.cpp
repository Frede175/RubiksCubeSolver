#include "stdafx.h"
#include "tree.h"

tree::tree(node * startNode) {
	stack.push(startNode);
	//nodes.push_back(startNode);
}

void tree::findSolution(std::vector<RubikAction_T> * outArray) { 
	if (RubiksHelper::isSolved(&(stack.front()->getData()))) return; //Check if cube is allready solved
	int lastDepth = 1;
	int checkedNodes = 0;
	bool solution = false;
	node * solutionNode = nullptr;

	while (!solution && !stack.empty()) {
		node * currentNode = stack.front();
		//std::cout << unsigned(currentNode->getDepth()) << "\n";
		if (currentNode->getDepth() != lastDepth) {
			std::cout << unsigned(currentNode->getDepth()) << "\n";
			lastDepth = currentNode->getDepth();
		}

		//if (sizeof(nodes) % 1000 == 0) std::cout << unsigned(sizeof(nodes)) << "\n";

		solutionNode = processNode(currentNode);
		if (solutionNode != nullptr) {
			solution = true;
		} else {
			checkedNodes++;
			if (checkedNodes % 1000 == 0) std::cout << checkedNodes << "\n";
			cubes.push_back(RubiksHelper::convertToNumber(&(currentNode->getData())));
			stack.pop();
		}
		
	}

	bool instructionsFound = false;

	while (!instructionsFound) {
		if (solutionNode == nullptr) {
			instructionsFound = true;
		} else {
			outArray->insert(outArray->begin(), *(solutionNode->getLastAction()));
			solutionNode = solutionNode->getParrent();
		}
	}
}


node * tree::processNode(node * currentNode) {
	RubikCube_T currentCube = currentNode->getData();
	RubikAction_T * action = currentNode->getLastAction();
	for (int a = 0; a < 18; a++) {
		if (!action || action->action != Actions[a].action) {
			RubikCube_T newCube = currentCube;
			RubiksHelper::rotateCube(&newCube, Actions[a].action, Actions[a].rotations);
			std::string number = RubiksHelper::convertToNumber(&newCube);
			bool contains = false;
			for (std::vector<std::string>::iterator it = cubes.begin(); it < cubes.end(); ++it) {
				if (!number.compare(*it)) {
					//return nullptr;
					//std::cout << "Same: " << *it << ", " << number << "\n";
					contains = true;
					break;
				}	
			} 
			if (!contains) {
				node * newNode = new node(currentNode, &(Actions[a]), newCube, uint8_t(currentNode->getDepth() + 1));
				if (RubiksHelper::isSolved(&newCube)) {
					std::cout << "Solution found! \n";
					return newNode;
				}
				currentNode->addNode(newNode);
				stack.push(newNode);
			}
			
		}
	}
	return nullptr;
}
