#include "Graph.h"
#include<iostream>
using namespace std;

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
	//if edge already exists,update weight 
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
				int x = it->second.size();
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
	for (auto del = adjList.find(src)->second.begin(); del != adjList.find(src)->second.end(); ++del)
		if (del->first == dest)
		{
			adjList[src].remove(*del);
			numEdges--;
			//adjlist[source].erase(del);
			return;
		}
}
void Graph::updateWeight(string src, string dest, int weight)
{
	bool found = false;
	for (auto move = adjList.find(src)->second.begin(); move != adjList.find(src)->second.end(); ++move)
	{
		if (move->first == dest)
		{
			move->second = weight;
			found = true;
			return;
		}
	}
	//if edge not found, offer to add it
	if (!found)
	{
		char ch;
		cout << " add it (Y|N) ? \n";
		cin >> ch;
		if (ch == 'y')
			addEdge(src, dest, weight);
		else
			return;
	}
}
//void Graph::Update()
//{
//	int ch;
//	cout << " 1 -> edit path , 2 -> add source , 3 -> add dest, 4 -> delete source , 3 -> delete dest ";
//	cin >> ch;
//	cin >> edge.src >> edge.dest >> edge.weight;
//	if (ch == 1)
//		updateWeight(edge.src, edge.dest, edge.weight);
//	else if (ch == 4)
//		deleteVertex(edge.src);
//	else if (ch == 5)
//		deleteEdge(edge.src, edge.dest);
//}
//check if two nodes are neighbours
bool Graph::areAdjacent(string src, string dest)
{    
		for (auto it2 = adjList.find(src)->second.begin(); it2 != adjList.find(src)->second.end(); it2++)
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
			if (it->second.empty())
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
