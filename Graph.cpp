#include "Graph.h"
#include<iostream>
#include <queue>
#include <vector>
#include <stack>
#include <functional> //for greater<> in priority queue, for sorting pq ascending
#define INF INT_MAX
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
int Graph::dijkstra(string src, string dest, stack<string>& ss)
{
	if (exists(src, dest))
	{
		priority_queue< dijkstraPair, vector <dijkstraPair>, greater<dijkstraPair> > pq;
		unordered_map<string, bool>visited;
		unordered_map<string, int>distance;
		unordered_map<string, string>parent;
		//initialization of nodes with infinity, unvisited
		for (auto it = adjList.begin(); it != adjList.end(); ++it)
		{
			visited[it->first] = 0;
			distance[it->first] = INF; //INT_MAX
		}
		distance[src] = 0; 
		pq.push(make_pair(0, src));
		while (!pq.empty())
		{
			int dist = pq.top().first; //distance from source to current node
			string s = pq.top().second; //node with shortest distance
			pq.pop();
			if (s == dest) //destination reached
				break;
			if (visited[s])
				continue;
			visited[s] = 1;
			//getting all adjacent vertices of s.
			for (auto it = adjList[s].begin(); it != adjList[s].end(); ++it)
			{
				if (distance[it->first] > dist + it->second)
				{
					distance[it->first] = dist + it->second; //update distance
					pq.push(make_pair(distance[it->first], it->first));
					parent[it->first] = s; //update parent
				}
			}
		}
		ss = buildPath(parent, dest);
		return distance[dest];
	}
	return -1;
}
stack<string> Graph::buildPath(unordered_map<string, string> parent, string dest)
{
	stack<string> s;
	s.push(dest);
	for (int i = 0; i < parent.size(); ++i)
	{
		s.push(parent[dest]);
		dest = parent[dest];
	}
	return s;
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
void Graph::Bellman(string src, string des)
{
	getIndex();
	vector<pair<int, string>> distance(numVertices());
	stack<string> backTrack;
	string city = des;
	int c = 0;
	for (int i = 0; i < numVertices(); ++i)
	{
		distance[i].first = INF;
	}
	distance[indicies[src]].first = 0;
	for (int i = 0; i < numVertices()-1; ++i)
	{
		c = 0;
		for (int j = 0; j < numEdges; ++j)
		{
			int s = edgesInd[j].first;
			int d = edgesInd[j].second.first;
			int w = edgesInd[j].second.second;
			if (distance[s].first != INF && distance[s].first + w < distance[d].first)
			{
				distance[d].first = distance[s].first + w;
				for (auto it = indicies.begin(); it != indicies.end(); ++it)
				{
					if (it->second == s)
						distance[d].second = it->first;
				}
				c++;
			}
		}
		if (c == 0)
		{
			break;
		}
	}
	backTrack.push(des);
	while (city != src)
	{
		backTrack.push(distance[indicies[city]].second);
		city = distance[indicies[city]].second;
	}
	cout << "Shortest path from " << src << " to " << des << ":" << endl << "Total distance: " << distance[indicies[des]].first << endl;
	cout << "Passing by: ";
	while (!backTrack.empty())
	{
		if (backTrack.size() == 1)
		{
			cout << backTrack.top();
		    backTrack.pop();
		}
		else
		{
		   cout << backTrack.top() << " -> ";
		   backTrack.pop();
		}
	}
	cout << endl << endl;
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
