void DFS_visit(Graph graph, int v, char * &color, int * &discover, int * &finish, int * &parent, vector<int>& path)
{
	discover[v - 1] = ttime++;
	color[v - 1] = 'g';
	list<int> neighbours = graph.getNeighbours(v);
	list<int>::iterator it;

	int u = -1;
	for (it = neighbours.begin(); it != neighbours.end(); ++it)
	{
		u = *it;
		if (color[u - 1] == 'w')
		{
			parent[u - 1] = v;
			path.push_back(u);
			DFS_visit(graph, u, color, discover, finish, parent, path);
		}
	}
	color[v - 1] = 'b';
	finish[v - 1] = ttime++;

}
vector<int> iterative_DFS_visit(Graph graph, int v, char * &color, int * &discover, int * &finish, int * &parent)
{
	vector<int>path;
	if (color[v - 1] == 'w')
	{
		int current = -1;
		list<int> neighbours;
		list<int>::reverse_iterator rit;
		list<int>::iterator it;
		stack<int> stack, visited;
		stack.push(v);
		while (!stack.empty())
		{
			current = stack.top();
			stack.pop();
			if (color[current - 1] == 'w')
			{
				//path updated
				visited.push(current);
				path.push_back(current);
				color[current - 1] = 'g';
				discover[current - 1] = ttime++;
				neighbours = graph.getNeighbours(current);
				if (neighbours.begin() != neighbours.end())
				{
					for (it = neighbours.begin(); it != neighbours.end(); ++it)
					{
						if (color[*it - 1] == 'w')
						{
							parent[*it - 1] = current;
							stack.push(*it);
						}
					}
				}
			}
		}
		while (!visited.empty())
		{
			current = visited.top();
			color[current - 1] = 'b';
			finish[current - 1] = ttime++;
			visited.pop();
		}
	}
	return path;
}
vector<int> DFS_vertex(Graph graph, int v, char * &color, int * &discover, int * &finish, int * &parent)
{
	vector<int>path;
	if (0 < v && v < graph.getV())
	{
		if (color[v - 1] == 'w')
		{
			path.push_back(v);
			path = iterative_DFS_visit(graph, v, color, discover, finish, parent);
		}
	}
	return path;
}
vector<vector<int>> DFS(Graph graph, int V, char * &color, int * &discover, int * &finish, int * &parent)
{
	vector<vector<int>> paths;
	//for whole graph
	for (int v = 1; v <= V; v++)
	{
		if (color[v - 1] == 'w')
		{
			paths.push_back(iterative_DFS_visit(graph, v, color, discover, finish, parent));
		}
	}
	return paths;
}
