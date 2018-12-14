#pragma once
#include<iostream>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
class Graph
{
	int EdgesNum;
	unordered_map < string, list<pair<string, int>>> adjlist;
public:
	struct Edge{
		int weight;
		string src;
		string dest;

	}edge;
	Graph(int num);
	void addGraph(int num);
	void addEdge();

	
	void deleteVertex(string);
	void deleteEdge(string, string);
	void editEdge(string, string, int);
	void Update();

	void displayGraph(int num);
	void deleteGraph();
	~Graph();
};

