#include "Graph.h"
#include<iostream>
#include <queue>
#include <vector>
#include <functional> //for greater, for sorting pq ascending
#define INF  INT_MAX
using namespace std;
typedef pair <int, string> dijkstraPair; //first of pair is the minimum distance, to ensure that pq is sorted acc. to distance. While dest. name is second of pair.

Graph::Graph()
{
	numEdges = 0;
}
void Graph::addVertex(string ver)
{
	if (adjList.find(ver) == adjList.end())
		adjList[ver];
}
void Graph::addEdge(string src, string dest, int weight)
{
	//if edge already exists, update weight 
	if (numEdges > 0 && areAdjacent(src, dest))
	{
		updateWeight(src, dest, weight);
		return;
	}
	adjList[src].push_back(make_pair(dest, weight));
	//check if destination is found
	addVertex(dest);
	numEdges++;
}
void Graph::deleteVertex(string vertex)
{
	//vertex not found
	if (adjList.find(vertex) == adjList.end())
		return;
	//deleting vertex as destination
	for (auto it = adjList.begin(); it != adjList.end(); ++it)
	{	
		for (auto o = it->second.begin(); o != it->second.end(); ++o)
		{
			if (o->first == vertex)
			{
				//adjlist[it->first].remove(*o);
				adjList[it->first].erase(o);
				break; //to avoid dereferincing an iterator to a non existing list
			}
		}
		//deleting vertex as source
	    if (it->first == vertex)
	    {
			adjList.find(vertex)->second.clear();
			adjList.erase(vertex);
		}
	}
}
void Graph::deleteEdge(string src, string dest)
{
	if (adjList.find(src) == adjList.end())
		return;
	for (auto del = adjList[src].begin(); del != adjList[src].end(); ++del)
		if (del->first == dest)
		{
			adjList[src].remove(*del);
			//adjList[source].erase(del);
			--numEdges;
			return;
		}
}
void Graph::updateWeight(string src, string dest, int weight)
{
	if (adjList.find(src) == adjList.end())
		return;
	for (auto move = adjList[src].begin(); move != adjList[src].end(); ++move)
	{
		if (move->first == dest)
		{
			move->second = weight;
			return;
		}
	}
	//if edge not found, offer to add it
	char ch;
	cout << " add it (Y|N) ? \n";
	cin >> ch;
	if (ch == 'y')
		addEdge(src, dest, weight);
}
//check if two nodes are neighbours
bool Graph::areAdjacent(string src, string dest)
{    
	if (adjList.find(src) == adjList.end())
		return false;
	for (auto it2 = adjList[src].begin(); it2 != adjList[src].end(); it2++)
		if (it2->first == dest)
			return true;
	return false;	
}
int Graph::numVertices()
{
	return(adjList.size());
}
void Graph::displayGraph()
{
	if (numVertices() > 0)
	{
		for (auto it = adjList.begin(); it != adjList.end(); ++it)
		{
			if (it->second.empty()) //vertex is only a destination
				continue;
			cout << it->first << " ";
			for (auto s = it->second.begin(); s != it->second.end(); ++s)
				cout << s->first << " " << s->second << " ";
			cout << endl;
		}
	}
	else return;
}
void Graph::deleteGraph()
{
	adjList.clear();
}
Graph::~Graph()
{
	deleteGraph();
}
