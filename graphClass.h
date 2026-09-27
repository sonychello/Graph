#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H


class Graph
{
public:


	Graph() :
		nNode_{ 0 }
	{}


	~Graph() {
		clear();
	}


	bool isEmpty() const;
	bool isNodeInGraph(const int node) const;
	bool isArcInGraph(const int firstNode, const int secondNode) const;
	bool insertNode(const int node);
	bool removeNode(const int node);
	bool insertEdge(const int nodeFrom, const int nodeTo);
	bool removeEdge(const int nodeFrom, const int nodeTo);
	int** getTable() const;
	size_t getNNode() const;
	void clear();

private:
	int nNode_;
	int** table_ = new int* [0];
};

#endif // !GRAPHCLASS_H



