#pragma once
#include<iostream>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
class Edge{
public:
	int weight;
	string src;
	string dest;
	Edge();
	~Edge();

};
class Graph
{
	int EdgesNum;
	unordered_map < string, list<pair<string, int>>>adjlist;
	Edge edge;
public:
	
	Graph(int);
	void addGraph(int);
	void addEdge();
	void addVertex(string);
	void displayGraph(int);
	void deleteGraph();
	~Graph();
};

