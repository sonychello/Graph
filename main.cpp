#include "graphClass.h"
#include "function.h"


int main()
{
	Graph graph;
	std::string command;
	std::cout << "Empty graph was create.\n\n\tList of commands:\n";
	std::cout << "Insert_node <node>\n"
		<< "Insert_edge <nodeFrom nodeTo>\n"
		<< "Remove_node <node>\n"
		<< "Remove_edge <nodeFrom nodeTo>\n"
		<< "Find_node <node>\n"
		<< "Find_edge <nodeFrom nodeTo>\n"
		<< "Empty\n"
		<< "Remove_cycles_and_multipleEdge\n"
		<< "Find_Drains_and_Sources\n"
		<< "Find_Vertex_of_Max_Degree\n"
		<< "Count_Outgoing_and_Incoming_Degrees\n"
		<< "Print\n\n";
	std::cout << "Enter command\n";
	while (std::cin >> command) {
		try {
			processingCommand(command, graph);
		}
		catch (std::exception ex) {
			std::cerr << "Error: " << ex.what() << "\n";
		}
		std::cout << "\nEnter command\n";
	}
	return 0;
}

