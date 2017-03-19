#include "stdafx.h"
#include "tree.h"

tree::tree(node * startNode) {
	stack.push(startNode);
	nodes.push_back(startNode);
}

void tree::findSolution(std::vector<RubikAction_T> * outArray) { 
	if (RubiksHelper::isSolved(&(stack.front()->getData()))) return; //Check if cube is allready solved
	int lastDepth = 1;
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
			nodes.push_back(currentNode);
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

	for (int a = 0; a < 27; a++) {
		if (action != &Actions[a]) {
			RubikCube_T newCube = currentCube;

			RubiksHelper::rotateCube(&newCube, Actions[a].action, Actions[a].rotations);

			auto pred = [newCube](node * item) {
				//std::cout << "Called";
				for (int f = 0; f < 6; f++) {
					for (int y = 0; y < 3; y++) {
						for (int x = 0; x < 3; x++) {
							if ((*item).getData().cube[f][y][x] != newCube.cube[f][y][x]) {
								//std::cout << unsigned((*item).getData().cube[f][y][x]) << ":" << unsigned(newCube.cube[f][y][x]) << " " << unsigned(f) << " " << unsigned(y) << " " << unsigned(x) << "\n";
								return false;
							}
						}
					}
				}
				return true;
			};



			if (std::find_if(nodes.begin(), nodes.end(), pred) != nodes.end()) {
				//std::cout << "Same";
				continue;
			} else {
				node * newNode = new node(currentNode, &(Actions[a]), newCube, uint8_t(currentNode->getDepth() + 1));
				if (RubiksHelper::isSolved(&newCube)) {
					std::cout << "Solution found! \n";
					return newNode;
				}
				currentNode->addNode(newNode);
				//nodes.push_back(*newNode);
				stack.push(newNode);
			}
		}
	}

	return nullptr;
}
