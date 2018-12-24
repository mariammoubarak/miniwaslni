#pragma once
#include<string>
#include<list>
#include<unordered_map>
#include <queue>
#include <vector>
#include <stack>
#include <functional> //for greater, for sorting pq ascending
#define INF  INT_MAX



using namespace std;
class graph
{
	unordered_map <int, pair<int, pair<int, int>>> edgesInd;
	unordered_map<string, int>indicies;
public:
	int numEdges;
	stack<string> backTrack;
	graph();
	unordered_map<string, list<pair<string, int>>> adjList;

	void addVertex(string ver)
	{
		if (adjList.find(ver) == adjList.end())
			adjList[ver];
	}
	void addEdge(string src, string dest, int weight)
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
	void updateWeight(string src, string dest, int weight)
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
	}
	bool areAdjacent(string src, string dest)
	{
		for (auto it2 = adjList.find(src)->second.begin(); it2 != adjList.find(src)->second.end(); it2++)
		if (it2->first == dest)
			return true;
		return false;
	}
	void deleteVertex(string vertex)
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
	void deleteEdge(string src, string dest)
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
	int Graph::BellmanFord(string src, string des, stack<string>& backTrack)
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
		if (distance[des].first == INF) //No possible path between the given source and destination
		{
			cout << "No path from " << src << " to " << des << endl;
			return INF;
		}
		else
		{

		 backTrack = buildPath(distance, src, des);
		 return distance[des].first;
		}
	}
	return INF; //if destination is unreachable
}
	
	void Graph::DFS(string src, vector<string>& nodes)
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
		nodes.push_back(traverse.top());
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
	int numVertices()
	{
		return(adjList.size());
	}
	void deleteGraph()
	{
		adjList.clear();
	}
	~graph()
	{
		deleteGraph();
	}
};

