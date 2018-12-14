#include "Graph.h"
#include<iostream>
using namespace std;

Graph::Graph(int num)
{
	numEdges = num;
}
void Graph::addGraph(int num)
{
	for (int i = 0; i < num; ++i)
	{
		cin >> edge.src >> edge.dest >> edge.weight;
		addEdge(edge.src, edge.dest, edge.weight);
	}		
}
void Graph::addVertex(string ver)
{
	if (adjlist.find(ver) == adjlist.end())
		adjlist[ver];
}
void Graph::addEdge(string src, string dest, int weight)
{
	adjlist[src].push_back(make_pair(dest, weight));
	if (adjlist.find(dest) == adjlist.end())
		adjlist[dest];
}
bool Graph::areAdjacent(string src, string dest)
{
	unordered_map <string, list<pair<string, int>>>::iterator it1 = adjlist.find(src);
	list<pair<string, int>>::iterator it2;
	for (list<pair<string, int>>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
	if (it2->first == dest)
		return true;
	return false;
}
int Graph::numVertices()
{
	return(adjlist.size());
}
void Graph::displayGraph(int)
{
	for (auto it = adjlist.begin(); it != adjlist.end(); ++it)
	{
		cout << it->first << " ";
		for (list<pair<string, int>>::iterator s = it->second.begin(); s != it->second.end(); ++s)
			cout << s->first << " " << s->second << " ";
		cout << endl;
	}
}
void Graph::deleteGraph()
{
	adjlist.clear();
}
Graph::~Graph()
{
	deleteGraph();
}
