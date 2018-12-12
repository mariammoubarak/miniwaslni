#include "Graph.h"
#include<iostream>
using namespace std;
Edge::Edge()
{
	 weight=0;
	 src="";
	 dest="";
}
Graph::Graph(int num)
{
	EdgesNum = num;
}
void Graph::addGraph(int num)
{
	for (int i = 0; i < num; ++i)
		addEdge();
}
void Graph::addVertex(string ver)
{
	
	if (adjlist.find(ver) == adjlist.end())
		adjlist[ver];
}
void Graph::addEdge()
{   cin >>edge.src;
	cin >>edge.dest;
	cin >>edge.weight;
	adjlist[edge.src].push_back(make_pair(edge.dest,edge. weight));
	if (adjlist.find(edge.dest) == adjlist.end())
		adjlist[edge.dest];
}
void Graph::displayGraph(int num)
{
	for (auto it = adjlist.begin(); it != adjlist.end(); ++it){
		cout << it->first << " ";
		for (list<pair<string, int>>::iterator s = it->second.begin(); s != it->second.end(); ++s){
			cout << s->first << " " << s->second << " ";
		}
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
Edge::~Edge()
{
}
