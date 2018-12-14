void Graph::deleteVertex(string Vertex)
{
	unordered_map<string, list<pair<string, int>>>::iterator it;
	list<pair<string, int>>::iterator o;

	it = adjlist.find(Vertex);
	if (it == adjlist.end())
		return;
	else
	{
		it->second.clear(); 
		adjlist.erase(Vertex);

	}
	for (it = adjlist.begin(); it != adjlist.end(); ++it)
	{
		list<pair<string, int>>::iterator o = it->second.begin();
		while (o != it->second.end())
		{
			if (o->first == Vertex)
			{
				//adjlist[it->first].remove(*o);
				adjlist[it->first].erase(o);
				return;
			}
			else
				++o;
		}
		// // the inner loop
		//for (o = it->second.begin(); o != it->second.end();++o )
		//{
		//	if (o->first == Vertex)
		//	{
		//		//adjlist[it->first].remove(*o);
		//		 adjlist[it->first].erase(o);
		//	}
		//}
	}


}

void Graph::deleteEdge(string source, string Dest)
{

	unordered_map<string, list<pair<string, int>>>::iterator it = adjlist.find(source);
	if (it == adjlist.end())
		return;
	else
	{
		list<pair<string, int>>::iterator del = it->second.begin();
		while (del != it->second.end())
		{
			if (del->first == Dest)
			{
				adjlist[edge.src].remove(*del);
				//adjlist[source].erase(del);
				return;
			}
			else
				++del;
		}
	}
}

void Graph::editEdge(string src, string dest, int cost)
{

	bool found = false;

	unordered_map<string, list<pair<string, int>>>::iterator it = adjlist.find(src);
		for (list<pair<string, int>>::iterator Move = it->second.begin(); Move != it->second.end(); ++Move){
			if (Move->first == dest){
				Move->second = cost;
				found = true;
				/*delDest(src, dest);
				addDest(src, dest, cost);*/
			}
		}
	
		if (!found){
			char ch;
			cout << " add it (Y|N) ? \n";
			cin >> ch;

			/*if (ch == 'y')
				addDest(src, dest, cost);*/
			/*else
				return;*/
		}
}

void Graph::Update()
{
	int ch;
	cout << " 1 -> edit path , 2 -> add source , 3 -> add dest, 4 -> delete source , 3 -> delete dest ";
	cin >> ch;

	cin >> edge.src >> edge.dest >> edge.weight;
	if (ch == 1)
		editEdge(edge.src, edge.dest, edge.weight);
		else if (ch == 4)
			deleteVertex(edge.src);
		else if (ch == 5)
			deleteEdge(edge.src, edge.dest);
}
