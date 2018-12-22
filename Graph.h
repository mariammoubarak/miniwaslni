#pragma once
#include<string>
#include<list>
#include<unordered_map>
#include <stack>
#include <vector>
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
	int Bellman(string, string, stack<string>&);
	stack<string> buildPath(unordered_map<string, pair<int, string>>, string, string);
	void getIndex();
	void DFS(string);
	vector<string> BFS(string);
	void displayGraph();
	bool areAdjacent(string, string);
	int numVertices();
	void deleteGraph();
	~Graph();
};
