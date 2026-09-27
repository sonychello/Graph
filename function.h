#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "graphClass.h"
#include <iostream>

void countOutgoingIncomingDegrees(const Graph& obj) {
	if (obj.isEmpty()) {
		throw std::invalid_argument("Graph is empty");
	}
	std::cout << "   Outgoing   Incoming\n";
	int outgoingDegrees;
	int incomingDegrees;
	for (int i = 0; i < obj.getNNode(); i++) {
		if (obj.isNodeInGraph(i)) {
			outgoingDegrees = 0;
			incomingDegrees = 0;
			for (int j = 0; j < obj.getNNode(); j++) {
				if (obj.isNodeInGraph(j)) {
					outgoingDegrees += obj.getTable()[i][j];
					incomingDegrees += obj.getTable()[j][i];
				}
			}
			std::cout << i << ":\t";
			if (outgoingDegrees == 0) { std::cout << "\t"; }
			else { std::cout << outgoingDegrees << "\t"; }
			if (incomingDegrees == 0) { std::cout << "\n"; }
			else { std::cout << incomingDegrees << "\n"; }
		}
	}
}


void foundVertexOfMaxDegree(const Graph& obj) {
	if (obj.isEmpty()) {
		throw std::invalid_argument("Graph is empty");
	}
	int vertexOfMaxDegree = -1;
	int maxDegree = 0;
	for (int i = 0; i < obj.getNNode(); i++) {
		if (obj.isNodeInGraph(i)) {
			int degree = 0;
			for (int j = 0; j < obj.getNNode(); j++) {
				if (obj.isNodeInGraph(j)) {
					degree = degree + obj.getTable()[i][j] + obj.getTable()[j][i];
				}
			}
			if (degree > maxDegree) {
				vertexOfMaxDegree = i;
				maxDegree = degree;
			}
		}
	}
	std::cout << "Number of vertex of max degree: " << vertexOfMaxDegree << '\n';
}


bool removeMultipleEdgesCycles(Graph& obj) {
	try {
		if (obj.isEmpty()) {
			throw 0;
		}
		int nNode = obj.getNNode();
		for (int i = 0; i < nNode; ++i) {
			for (int j = 0; j < nNode; ++j) {
				if (i == j && obj.getTable()[i][j] != 0 && obj.isNodeInGraph(i) && obj.isNodeInGraph(j)) { obj.getTable()[i][j] = 0; }
				else {
					if (obj.getTable()[i][j] > 1)
					{
						obj.getTable()[i][j] = 1;
					}
					if (obj.getTable()[j][i] > 1)
					{
						obj.getTable()[j][i] = 1;
					}
				}
			}
		}
		return true;
	}
	catch (...) {
		std::cerr << "Error: MultipleEdges and Cycles didn't remove\n";
		return false;
	}
}


void foundDrainsSources(const Graph& obj) {
	if (obj.isEmpty()) {
		throw std::invalid_argument("Graph is empty");
	}
	else {
		std::cout << "   Sources   Drains\n";
		int outgoingDegrees;
		int incomingDegrees;
		for (int i = 0; i < obj.getNNode(); i++) {
			if (obj.isNodeInGraph(i)) {
				outgoingDegrees = 0;
				incomingDegrees = 0;
				for (int j = 0; j < obj.getNNode(); j++) {
					if (obj.isNodeInGraph(j)) {
						outgoingDegrees += obj.getTable()[i][j];
						incomingDegrees += obj.getTable()[j][i];
					}
				}
				std::cout << i << ":\t";
				if (outgoingDegrees == 0) { std::cout << "+\t"; }
				else { std::cout << " \t"; }
				if (incomingDegrees == 0) { std::cout << "+\n"; }
				else { std::cout << "\n"; }
			}
		}
	}
}

void printGraph(const Graph& obj) {
	int nNode = obj.getNNode();
	if (!obj.isEmpty()) {
		std::cout << " ";
		for (int i = 0; i < nNode; ++i) {
			if (obj.isNodeInGraph(i)) {
				std::cout << " " << i;
			}
		}
		std::cout << "\n\n";
		for (int i = 0; i < nNode; ++i) {
			if (obj.isNodeInGraph(i)) {
				std::cout << i;
				for (int j = 0; j < nNode; ++j) {
					if (obj.getTable()[i][j] != -1) {
						std::cout << " " << obj.getTable()[i][j];
					}
				}
				std::cout << "\n\n";
			}
		}
	}
	else throw std::invalid_argument("Graph is empty");
}


void processingCommand(const std::string command, Graph& obj) {

	if (command == "Insert_node") {
		int node;
		std::cin >> node;
		if (std::cin.good()) {
			if (obj.insertNode(node)) {
				std::cout << "Node " << node << " added.\n";
			}
			else throw std::invalid_argument("Node is in graph or invalid argument");
		}
		else throw std::invalid_argument("Invalid command");
	}


	else if (command == "Insert_edge") {
		int from, to;
		std::cin >> from >> to;
		if (std::cin.good()) {
			if (obj.insertEdge(from, to)) {
				std::cout << "Edge from " << from << " to " << to << " added.\n";
			}
		}
		else throw std::invalid_argument("Invalid command");
	}


	else if (command == "Remove_node") {
		int node;
		std::cin >> node;
		if (std::cin.good()) {
			if (obj.removeNode(node)) {
				std::cout << "Node " << node << " removed.\n";
			}
			else throw std::invalid_argument("Node is not in graph or graph is empty");
		}
		else throw std::invalid_argument("Invalid command");
	}


	else if (command == "Remove_edge") {
		int from, to;
		std::cin >> from >> to;
		if (std::cin.good()) {
			if (obj.removeEdge(from, to)) {
				std::cout << "Edge from " << from << " to " << to << " removed.\n";
			}
		}
		else throw std::invalid_argument("Invalid command");
	}


	else if (command == "Find_node") {
		int node;
		std::cin >> node;
		if (std::cin.good()) {
			if (obj.isNodeInGraph(node)) {
				std::cout << "Node " << node << " found.\n";
			}
			else throw std::invalid_argument("Node not found");
		}
		else throw std::invalid_argument("Invalid command");
	}


	else if (command == "Find_edge") {
		int from, to;
		std::cin >> from >> to;
		if (std::cin.good()) {
			if (obj.isArcInGraph(from, to)) {
				std::cout << "Edge from " << from << " to " << to
					<< " found.\n";
			}
			else throw std::invalid_argument("Edge not found");
		}
		else throw std::invalid_argument("Invalid command");
	}


	else if (command == "Empty") {
		if (obj.isEmpty()) {
			std::cout << "Graph is empty.\n";
		}
		else { std::cout << "Graph is not empty.\n"; }
	}


	else if (command == "Remove_cycles_and_multipleEdge") {
		if (removeMultipleEdgesCycles(obj)) {
			std::cout << "Cycles and MultipleEdge removed.\n";
		}
	}


	else if (command == "Find_Drains_and_Sources") {
		foundDrainsSources(obj);
	}


	else if (command == "Find_Vertex_of_Max_Degree") {
		foundVertexOfMaxDegree(obj);
	}


	else if (command == "Count_Outgoing_and_Incoming_Degrees") {
		countOutgoingIncomingDegrees(obj);
	}


	else if (command == "Print") {
		printGraph(obj);
	}
	else {
		std::cin.setstate(std::ios::eofbit);
		throw std::invalid_argument("Invalid command");
	}
}

#endif // !FUNCTIONS_H
