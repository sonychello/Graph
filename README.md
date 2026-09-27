# Algorithms for Working with Graphs

A console C++ application implementing a directed graph data structure and a set of algorithms for working with graphs.

The project was developed as part of the **Algorithms and Data Structures** course.

## Task

The project implements a directed graph represented by an **adjacency matrix**.

The required graph operations include:

* creating an empty graph;
* checking whether the graph is empty;
* checking whether a vertex exists;
* checking whether an edge exists;
* adding a vertex;
* removing a vertex;
* adding an edge;
* removing an edge;
* clearing the graph.

The program also supports additional operations required by the assignment.

## Variant

**Variant 2.1 — Sources and sinks of a directed graph**

The implemented algorithms are:

1. Determining the incoming and outgoing degree of each vertex.
2. Finding the vertex with the maximum degree.
3. Removing multiple edges and cycles from a multigraph.
4. Finding sources and sinks of a directed graph.

## Graph Representation

The graph is represented using a dynamically allocated adjacency matrix.

Each matrix cell contains:

* `0` — there is no edge between the vertices;
* a positive value — the number of edges between the vertices;
* `-1` — the vertex is empty or has been removed.

The use of positive values instead of only `0` and `1` allows the structure to represent **multiple edges**.

The graph is directed, so an edge from vertex `A` to vertex `B` is stored separately from an edge from `B` to `A`.

## `Graph` Class

The main graph structure is implemented in the `Graph` class.

| Method            | Description                                    |
| ----------------- | ---------------------------------------------- |
| `isEmpty()`       | Checks whether the graph is empty              |
| `isNodeInGraph()` | Checks whether a vertex exists                 |
| `isArcInGraph()`  | Checks whether an edge exists                  |
| `insertNode()`    | Adds a vertex                                  |
| `removeNode()`    | Removes a vertex                               |
| `insertEdge()`    | Adds an edge                                   |
| `removeEdge()`    | Removes an edge                                |
| `getTable()`      | Returns the adjacency matrix                   |
| `getNNode()`      | Returns the current matrix size                |
| `clear()`         | Clears the graph and releases allocated memory |

## Algorithms

### Incoming and Outgoing Degrees

For every active vertex, the program calculates:

* outgoing degree — the number of edges leaving the vertex;
* incoming degree — the number of edges entering the vertex.

The results are displayed as a table.

### Maximum Degree Vertex

The program calculates the total degree of each vertex as the sum of its incoming and outgoing degrees and finds the vertex with the maximum value.

### Removing Multiple Edges and Cycles

The program processes the adjacency matrix and:

* removes loops from a vertex to itself;
* replaces multiple edges between two vertices with a single edge.

As a result, the graph no longer contains cycles of length one or multiple parallel edges.

### Sources and Sinks

The program determines vertices that satisfy the corresponding incoming and outgoing degree conditions for sources and sinks.

## Console Commands

The application supports the following commands:

```text
Insert_node <node>
Insert_edge <nodeFrom nodeTo>
Remove_node <node>
Remove_edge <nodeFrom nodeTo>
Find_node <node>
Find_edge <nodeFrom nodeTo>
Empty
Remove_cycles_and_multipleEdge
Find_Drains_and_Sources
Find_Vertex_of_Max_Degree
Count_Outgoing_and_Incoming_Degrees
Print
```

### Example

Adding two vertices and an edge:

```text
Insert_node 1
Insert_node 2
Insert_edge 1 2
Print
```

The `Print` command displays the current vertices and their adjacency matrix.

## Error Handling

The program validates user input and handles invalid operations.

Examples of invalid operations include:

* adding a negative vertex;
* adding an already existing vertex;
* removing a non-existent vertex;
* adding an edge when one or both vertices do not exist;
* removing a non-existent edge;
* executing graph algorithms on an empty graph;
* entering an unknown command.

Errors are reported in the console, and the program continues processing input where possible.

## Complexity

The graph uses an adjacency matrix, therefore:

* checking an edge — `O(1)`;
* removing an edge — `O(1)`;
* searching for a vertex — `O(n)`;
* removing a vertex — `O(n)`;
* adding a new vertex — `O(n²)`;
* algorithms that scan the entire matrix — `O(n²)`;
* memory consumption — `O(n²)`.

## Project Structure

```text
Graph/
├── graphClass.h
├── graphClass.cpp
├── functions.h
└── main.cpp
```

### `graphClass.h`

Contains the declaration of the `Graph` class and its methods.

### `graphClass.cpp`

Contains the implementation of graph operations, including vertex and edge insertion/removal, matrix management, and memory cleanup.

### `functions.h`

Contains auxiliary functions for graph algorithms, output, and command processing.

### `main.cpp`

Contains the program entry point and console interaction.

## Technologies

* **C++**
* Object-oriented programming
* Dynamic memory management
* Adjacency matrix
* Graph algorithms
* Exception handling
* Console input/output

## Testing

The program is designed to handle both valid and invalid input sequences.

The tested scenarios include:

* operations on an empty graph;
* adding and removing vertices;
* adding and removing edges;
* searching for vertices and edges;
* processing multiple edges and cycles;
* finding sources and sinks;
* finding the vertex with the maximum degree;
* calculating incoming and outgoing degrees;
* handling invalid commands and arguments.

## Author

**Sofya Pozneeva**

Saint Petersburg Polytechnic University
Institute of Computer Science and Cybersecurity
Higher School of Software Engineering

Course: **Algorithms and Data Structures**

Year: **2025**
