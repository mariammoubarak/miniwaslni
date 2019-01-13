#pragma once

#include <windows.h>
#include<string>
#include<list>
#include<unordered_map>
#include <stack>
#include <vector>
#include <queue>
#include <functional> //for greater<> in priority queue, for sorting pq ascending
#define INF INT_MAX
#define dijkstraPair pair <int, string> //first of pair is the minimum distance, to ensure that pq is sorted acc. to distance. While dest. name is second of pair.
using namespace std;
using namespace System::Windows::Forms;
class graph
 {
 public:
	 class Index //for Floyd
	 {
	 public:
		 int label;
		 string cityName;
	 }index;
	 vector<Index>v;
	 int numEdges;
	 unordered_map <string, list<pair<string, int>>> adjList; //public for floyd class 
	 graph();
	int numVertices()
	{
		return(adjList.size());
	}

	void addEdge(string src, string dest, int weight)
	{
		if (src == dest)
		{
			MessageBox::Show("Source and Destination are the same", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
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

	void addVertex(string ver)
	{
		if (adjList.find(ver) == adjList.end())
		{
			adjList[ver]; // add it as a source only 
		}
	}

	void deleteVertex(string vertex)
	{
		//vertex not found
		if (adjList.find(vertex) == adjList.end())
		{
			return;
		}
		//deleting vertex as destination
			for (auto it = adjList.begin(); it != adjList.end(); ++it)
			{
				for (auto o = it->second.begin(); o != it->second.end(); ++o)
				{
					if (o->first == vertex)
					{
						//adjlist[it->first].remove(*o);
						adjList[it->first].erase(o);
						--numEdges;
						break; //to avoid dereferincing an iterator to a non existing list
					}
				}
			}
		//deleting vertex as source
			numEdges -= adjList[vertex].size(); //deleting number of edges connected to source
			adjList[vertex].clear();
			adjList.erase(vertex);
	}

	void deleteEdge(string src, string dest)
	{
		if (adjList.find(src) == adjList.end())
		{
			return;
		}
		for (auto del = adjList[src].begin(); del != adjList[src].end(); ++del)
		{
			if (del->first == dest)
			{
				adjList[src].remove(*del);
				--numEdges;
				return;
			}
		}
	}

	void updateWeight(string src, string dest, int weight)
	{
		if (adjList.find(src) == adjList.end() || adjList.find(dest) == adjList.end())
		{
			return;
		}
		for (auto move = adjList[src].begin(); move != adjList[src].end(); ++move)
		{
			if (move->first == dest)
			{
				move->second = weight;
				return;
			}
		}
		MessageBox::Show("A NON existing Path will be updated !! \n Destenation not connected with this city", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	bool exists(string src, string dest)
	{
		//destination is the same as source
		if (src == dest)
		{
			return false;
		}
		//making sure that both source and destination nodes are found in graph.
		if (adjList.find(src) == adjList.end())
		{
			if (adjList.find(dest) == adjList.end())
			{
				MessageBox::Show("Both cities don't exist in graph ", "Shortest Path not Available", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}
			MessageBox::Show("Source city doesn't exist in graph ", "Shortest Path not Available", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (adjList.find(dest) == adjList.end())
		{
			MessageBox::Show("Destination city doesn't exist in graph ", "Shortest Path not Available", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		//given source is only a destination
		if (adjList[src].empty())
		{
			MessageBox::Show("No path from the current city  to the desired city , as the current city is only a destination ", "warning ");
			return false;
		}
		//given destination is only a source
		for (auto it = adjList.begin(); it != adjList.end(); ++it)
		{
			for (auto o = it->second.begin(); o != it->second.end(); ++o)
			{
				if (o->first == dest)
				{
					return true;
				}
			}
		}
		MessageBox::Show("No path from the current city to the desired city, as the desired city is only a source.", "warning ");
		return false;
	}

	int dijkstra(string src, string dest, stack<string>& backtrack)
	{
		if (exists(src, dest))
		{
			priority_queue< dijkstraPair, vector <dijkstraPair>, greater<dijkstraPair> > pq;
			unordered_map<string, pair<int, string>>distance; //shortest distance as first of pair, parent of node in second of pair
			unordered_map<string, bool>visited;
			bool reached = false;
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
				{
					reached = true;
					break;
				}
				if (visited[source])
				{
					continue;
				}
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
			if (!reached)
			{
				MessageBox::Show( "No path from the current city to the desired city "," warning ");
				return INF;
			}
			backtrack = buildPath(distance, src, dest);
			return distance[dest].first;
		}
		return INF; //if destination is unreachable
	}
 	
	int BellmanFord(string src, string des, stack<string>& backTrack)
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
						if (distance[source].first != INF && distance[source].first + weight < distance[destination].first)
						{
							distance[destination].first = distance[source].first + weight;
							c++;
							distance[destination].second = source; //update shortest distance
						}
					}
				}
				if (c == 0) //no updates were made in the past iteration (All nodes reached the ultimate shortest path)
				{
					break;
				}
			}
			if (distance[des].first == INF) //No possible path between the given source and destination
			{
				MessageBox::Show("No path from the current city to the desired city .", "warning ");
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
		
	vector<vector<int>> floyd()
	{

		vector<vector<int>>floydMatrix(numVertices(), vector<int>(numVertices()));
		getIndex();

		int geti = 0, getj = 0, c = 0;
		//initializing the first matrix
		for (auto it = adjList.begin(); it != adjList.end(); ++it)
		{
			
			for (int i = 0; i < v.size(); ++i)
			{
				if (v[i].cityName == it->first)
				{
					geti = v[i].label;
				}
				else if (i != c && floydMatrix[c][i] == 0)
					floydMatrix[c][i] = INF;

			}
			for (auto s = it->second.begin(); s != it->second.end(); ++s)
			{
				for (int i = 0; i < v.size(); ++i)
				{
					if (v[i].cityName == s->first)
					{
						getj = v[i].label;
						floydMatrix[geti][getj] = s->second;
						break;
					}
				}
			}
			c++;
		}

		//getting the shortest path between any node
		for (int k = 0; k < numVertices(); ++k)
		{
			for (int i = 0; i < numVertices(); ++i)
			{
				for (int j = 0; j < numVertices(); ++j)
				{
					if (i == j || i == k || j == k)
					{
						continue;
					}
					if (floydMatrix[i][k] + floydMatrix[k][j] < floydMatrix[i][j] && (floydMatrix[i][k] != INF && floydMatrix[k][j] != INF))
					{
						floydMatrix[i][j] = floydMatrix[i][k] + floydMatrix[k][j];
					}
				}
			}
		}
		return floydMatrix;
	}

	stack<string> buildPath(unordered_map<string, pair<int, string>> distance, string src, string dest)
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

	void getIndex()
	{
		v.clear();
		int i = 0;
		for (auto it = adjList.begin(); it != adjList.end(); ++it)
		{
			index.cityName = it->first;
			index.label = i;
			v.push_back(index);
			++i;
		}
	}

	void DFS(string src, vector<string>& nodes)
	{
		unordered_map<string, bool> visited;
		stack<string> traverse;
		for (auto it = adjList.begin(); it != adjList.end(); ++it) //Initialize all nodes to be unvisited
		{
			visited[it->first] = 0;
		}
		visited[src] = 1;
		traverse.push(src);
		while (!traverse.empty())
		{
			src = traverse.top();   //Update src to loop on its children nodes
			nodes.push_back(traverse.top());   //store nodes in their order of display in the vector
			traverse.pop();
			for (auto o = adjList[src].begin(); o != adjList[src].end(); ++o)
			{
				if (!visited[o->first])
				{
					traverse.push(o->first);
					visited[o->first] = 1;
				}
			}
		}
	}

	void BFS(string start, vector<string>& traverse)
	{
		unordered_map<string, bool> visited;
		for (auto it = adjList.begin(); it != adjList.end(); ++it)
		{
			visited[it->first] = 0;
		}
		visited[start] = 1;
		queue<string>nodes;
		nodes.push(start);
		while (!nodes.empty())
		{
			start = nodes.front();
			traverse.push_back(nodes.front());
			nodes.pop();
			for (auto it = adjList[start].begin(); it != adjList[start].end(); ++it)
			{
				if (!visited[it->first])
				{
					visited[it->first] = 1;
					nodes.push(it->first);
				}
			}
		}
	}

	bool areAdjacent(string src, string dest)
	{
		if (adjList.find(src) == adjList.end())
		{
			return false;
		}
		for (auto it = adjList[src].begin(); it != adjList[src].end(); ++it)
		{
			if (it->first == dest)
			{
				return true;
			}
		}
		return false;
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
