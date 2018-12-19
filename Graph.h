#pragma once
#include<string>
#include<list>
#include<unordered_map>
using namespace std;

class Graph
{
	int numEdges;
	unordered_map <string, list<pair<string, int>>> adjList;

public:
	Graph();
	void addEdge(string, string, int);
	void addVertex(string);
	void deleteVertex(string);
	void deleteEdge(string, string);
	void updateWeight(string, string, int);
	void getIndex();
	void Bellman(string src, string des);
	void dijkstra(string, string);
	bool areAdjacent(string, string);
	int numVertices();
	void displayGraph();
	void deleteGraph();
	~Graph();
};
