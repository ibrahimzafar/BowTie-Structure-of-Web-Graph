vector<int> iterative_BFS_visit(Graph graph, int v, char * &color, int * &discover, int * &finish, int * &parent)
{
	vector<int>path;
	if (color[v - 1] == 'w')
	{
		int current = -1;
		list<int> neighbours;
		list<int>::iterator it;
		queue<int> queue;
		stack<int> visited;
		queue.push(v);
		while (!queue.empty())
		{
			current = queue.front();
			queue.pop();
			visited.push(current);
			if (color[current - 1] == 'w')
			{
				//path updated
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
							queue.push(*it);
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
vector<vector<int>> BFS(Graph graph, int V, char * &color, int * &discover, int * &finish, int * &parent)
{
	vector<vector<int>> paths;
	//for whole graph
	for (int v = 1; v <= V; v++)
	{
		if (color[v - 1] == 'w')
			paths.push_back(iterative_BFS_visit(graph, v, color, discover, finish, parent));
	}
	return paths;
}
