#pragma once
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
class Edge
{
public:
	int weight;
	string src, dest;
};
class Graph
{
	int numEdges;
	unordered_map <string, list<pair<string, int>>> adjList;
	Edge edge;
public:
	Graph();
	void addEdge(string, string, int);
	void addVertex(string);
	//void Update();
	void deleteVertex(string);
	void deleteEdge(string, string);
	void updateWeight(string, string, int);
	bool areAdjacent(string, string);
	int numVertices();
	void displayGraph();
	void deleteGraph();
	~Graph();
};
