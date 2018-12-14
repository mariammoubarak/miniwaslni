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
	Edge();
};
class Graph
{
	int numEdges;
	unordered_map <string, list<pair<string, int>>> adjlist;
	Edge edge;
public:

	Graph(int);
	void addGraph(int);
	void addEdge(string, string, int);
	void addVertex(string);
	bool areAdj(string, string);
	void displayGraph(int);
	void deleteGraph();
	~Graph();
};
