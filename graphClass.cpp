#include "graphClass.h"
#include <iostream>
#include <cmath>


int** Graph::getTable() const {
	return table_;
}


size_t Graph::getNNode() const {
	return nNode_;
}


bool Graph::isEmpty() const {
	return nNode_ == 0;
}


bool Graph::isNodeInGraph(const int node) const {
	bool flag = false;
	if (node >= 0 && node < nNode_) {
		for (int j = 0; j < nNode_; ++j) {
			if (table_[node][j] != -1) {
				flag = true;
				break;
			}
		}
		return flag;
	}
	else return false;
}


bool Graph::isArcInGraph(const int firstNode, const int secondNode) const {
	if (isNodeInGraph(firstNode) && isNodeInGraph(secondNode)) {
		return table_[firstNode][secondNode] != 0;
	}
	return false;
}


void Graph::clear() {
	if (table_) {
		for (int i = 0; i < nNode_; ++i) {
			delete[] table_[i];
		}
		delete[] table_;
		table_ = nullptr;
	}
	nNode_ = 0;
}


bool Graph::insertNode(const int node) {
	try {
		if (!isNodeInGraph(node) && node >= 0) {
			if (node < nNode_) {
				for (int i = 0; i < nNode_; ++i) {
					if (i == node || isNodeInGraph(i)) {
						table_[i][node] = 0;
						table_[node][i] = 0;
					}
				}
			}


			else {
				int newSize = node + 1;
				int** newTable = new int* [newSize];
				for (int i = 0; i < newSize; ++i) {
					newTable[i] = new int[newSize];
					std::fill(newTable[i], newTable[i] + newSize, -1);
				}

				for (int i = 0; i < newSize; ++i) {
					if (i == node || isNodeInGraph(i)) {
						newTable[i][node] = 0;
						newTable[node][i] = 0;
					}
				}

				for (int i = 0; i < nNode_; ++i) {
					for (int j = 0; j < nNode_; ++j) {
						newTable[i][j] = table_[i][j];
					}
				}

				clear();
				table_ = newTable;
				nNode_ = newSize;
				return true;
			}
		}
		else return false;
	}
	catch (...) {
		std::cerr << "Error: Node didn't insert\n";
		return false;
	}
}


bool Graph::removeNode(const int node) {
	try {
		if (isNodeInGraph(node)) {
			for (int i = 0; i < nNode_; i++) {
				table_[node][i] = -1;
				table_[i][node] = -1;
			}
			return true;
		}
		else return false;

	}
	catch (...) {
		std::cerr << "Error: Node didn't remove\n";
		return false;
	}
}


bool Graph::insertEdge(const int nodeFrom, const int nodeTo) {
	try {
		if (isNodeInGraph(nodeFrom) && isNodeInGraph(nodeTo)) {
			table_[nodeFrom][nodeTo]++;
			return true;
		}
		else throw std::invalid_argument("Not one or both node in graph.");
	}
	catch (std::exception ex) {
		std::cerr << "Error: " << ex.what() << "\n";
		return false;
	}
}


bool Graph::removeEdge(const int nodeFrom, const int nodeTo) {
	try {
		if (isNodeInGraph(nodeFrom) && isNodeInGraph(nodeTo)
			&& table_[nodeFrom][nodeTo] > 0) {
			table_[nodeFrom][nodeTo]--;
			return true;
		}
		else {
			throw std::invalid_argument("Not one or both node in graph, not this edge in graph or graph is empty.");
		}
	}
	catch (std::exception ex) {
		std::cerr << "Error: " << ex.what() << '\n';
		return false;
	}
}
