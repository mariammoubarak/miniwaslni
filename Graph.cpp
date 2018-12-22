#include "Graph.h"
#include<iostream>
#include <queue>
#include <vector>
#include <stack>
#include <functional> //for greater<> in priority queue, for sorting pq ascending
#define INF INT_MAX
#define dijkstraPair pair <int, string> //first of pair is the minimum distance, to ensure that pq is sorted acc. to distance. While dest. name is second of pair.
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
	////if edge not found, offer to add it
	//if (!found)
	//{
	//	char ch;
	//	cout << " add it (Y|N) ? \n";
	//	cin >> ch;
	//	if (ch == 'y')
	//		addEdge(src, dest, weight);
}
bool Graph::exists(string src, string dest)
{
	//destination is the same as source
	if (src == dest)
	{
		cout << "Desired destination is already the source.\n";
		return false;
	}
	//making sure that both source and destination nodes are found in graph.
	if (adjList.find(src) == adjList.end())
	{
		if (adjList.find(dest) == adjList.end())
		{
			cout << "Both cities don't exist in graph.\n";
			return false;
		}
		cout << src << " doesn't exist in graph.\n";
		return false;
	}
	if (adjList.find(dest) == adjList.end())
	{
		cout << dest << " doesn't exist in graph.\n";
		return false;
	}
	//given source is only a destination
	if (adjList[src].empty())
	{
		cout << "No path from " << src << " to " << dest << " as " << src << " is only a destination.\n";
		return false;
	}
	//given destination is only a source
	for (auto it = adjList.begin(); it != adjList.end(); ++it)
	{
		for (auto o = it->second.begin(); o != it->second.end(); ++o)
		{
			if (o->first == dest)
				return true;
		}
	}
	cout << "No path from " << src << " to " << dest << " as " << dest << " is only a source.\n";
	return false;
}
int Graph::dijkstra(string src, string dest, stack<string>& backtrack)
{
	if (exists(src, dest))
	{
		priority_queue< dijkstraPair, vector <dijkstraPair>, greater<dijkstraPair> > pq;
		unordered_map<string, pair<int, string>>distance; //shortest distance as first of pair, parent of node in second of pair
		unordered_map<string, bool>visited;
		//initialization of nodes with infinity, unvisited
		for (auto it = adjList.begin(); it != adjList.end(); ++it)
		{
			visited[it->first] = 0;
			distance[it->first].first = INF; //INT_MAX
		}
		distance[src].first = 0; 
		pq.push(make_pair(0, src));
		while (!pq.empty())
		{
			int dist = pq.top().first; //distance from source to current node
			string source = pq.top().second; //node with shortest distance
			pq.pop();
			if (source == dest) //destination reached
				break;
			if (visited[source])
				continue;
			visited[source] = 1;
			//getting all adjacent vertices of source.
			for (auto it = adjList[source].begin(); it != adjList[source].end(); ++it)
			{
				string destination = it->first;
				int weight = it->second;
				if (distance[destination].first > dist + weight)
				{
					distance[destination].first = dist + weight; //update distance
					pq.push(make_pair(distance[destination].first, destination));
					distance[destination].second = source; //update parent
				}
			}
		}
		backtrack = buildPath(distance, src, dest);
		return distance[dest].first;
	}
	return INF; //if destination is unreachable
}
int Graph::Bellman(string src, string des, stack<string>& backTrack)
{
	unordered_map<string, pair<int, string>> distance; //Map carries the city name as key, shortest path as first, and with respect to which city as second
	if (exists(src, des))
	{
		for (auto it = adjList.begin(); it != adjList.end(); ++it) //initializing all distances with infinity
		{
			distance[it->first].first = INF;
		}
		distance[src].first = 0; // initializing source shortest distance with zero
		for (int i = 0; i < numVertices(); ++i)
		{
			int c = 0;
			for (auto it = adjList.begin(); it != adjList.end(); ++it)
			{
				for (auto o = it->second.begin(); o != it->second.end(); ++o)
				{
					string source = it->first;
					string destination = o->first;
					int weight = o->second; //distance between current node and its destination
					if (distance[source].first!=INF && distance[source].first + weight < distance[destination].first)
					{
						distance[destination].first = distance[source].first + weight;
						c++;
						distance[destination].second = source; //update shortest distance
					}
				}
			}
			if (c == 0) //no updates were made in the past iteration (All nodes reached the ultimate shortest path)
				break;
		}
		backTrack = buildPath(distance, des);
		return distance[des].first;
	}
	return INF; //if destination is unreachable
}
stack<string> Graph::buildPath(unordered_map<string, pair<int, string>> distance, string src, string dest)
{
	stack<string> backtrack;
	backtrack.push(dest);
	while (distance[dest].second != src)
	{
		backtrack.push(distance[dest].second);
		dest = distance[dest].second;
	}
	backtrack.push(src);
	return backtrack;
}
void Graph::getIndex()
{
	int i = 0, j=0;
	list<pair<string, int>>::iterator o;
	for (auto it = adjList.begin(); it != adjList.end(); ++it)
	{
		indicies[it->first] = i;
		++i;
	}
	for (auto it = adjList.begin(); it != adjList.end(); ++it)
	{
		for (o = it->second.begin(); o != it->second.end(); ++o)
		{
			edgesInd[j] = make_pair(indicies[it->first], make_pair(indicies[o->first], o->second));
			++j;
		}
		
	}
}
void Graph::DFS(string src)
{
	unordered_map<string, bool> visited;
	stack<string> traverse;
	string tmp = src;
	for (auto it = adjList.begin(); it != adjList.end(); ++it)
	{
		visited[it->first] = 0;
	}
	visited[src] = 1;
	traverse.push(src);
	while (!traverse.empty())
	{
		cout << traverse.top() << endl;
		traverse.pop();
		for (auto o = adjList[tmp].begin(); o != adjList[tmp].end(); ++o)
		{
			if (visited[o->first] == 0)
			{
				traverse.push(o->first);
				visited[o->first] = 1;
			}
		}
		if (!traverse.empty())
			tmp = traverse.top();
	}
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
void Graph::deleteGraph()
{
	adjList.clear();
}
Graph::~Graph()
{
	deleteGraph();
}
