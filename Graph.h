#pragma once
#include<string>
#include<list>
#include<unordered_map>
#include <stack>
using namespace std;

class Graph
{
	int numEdges;
	unordered_map <string, list<pair<string, int>>> adjList;
	unordered_map <int, pair<int, pair<int, int>>> edgesInd;
	unordered_map<string, int>indicies;

public:
	Graph();
	void addEdge(string, string, int);
	void addVertex(string);
	void deleteVertex(string);
	void deleteEdge(string, string);
	void updateWeight(string, string, int);
	bool exists(string, string);
	int dijkstra(string, string, stack<string>&);
	int Bellman(string src, string des, stack<string>&);
	stack<string> buildPath(unordered_map<string, string>, string dest);
	void getIndex();
	void Bellman(string src, string des);
	bool areAdjacent(string, string);
	int numVertices();
	void displayGraph();
	void deleteGraph();
	~Graph();
};
