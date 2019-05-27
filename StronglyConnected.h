vector<pair<int, int>> order_indices(const int * input_array, int size)
{
	vector<pair<int, int>>a;
	for (int i = 0; i < size; i++)
	{
		a.push_back(make_pair(input_array[i], i + 1));
	}
	sort(a.begin(), a.end(), greater <>());
	return a;
}
void getStronglyConnected(Graph graph, string outputfile, char * &color, int * &discover, int * &finish, int * &parent)
{
	int V = graph.getV();
	resetParameters(color, discover, finish, parent, graph.getV());

	DFS(graph, V, color, discover, finish, parent);

	vector<list<int>> * complement(getComplement(graph.adj));
	Graph Complement(complement);

	int * gcfinish = new int[V]();
	resetParameters(color, discover, gcfinish, parent, graph.getV());

	//order_indices function sorts the vertexes in decreasing order of finish times, as is needed
	vector<pair<int, int>> VertexDecreasingF = order_indices(finish, V);

	vector<int> path;
	for (int i = 0; i < V; i++)
	{
		path = iterative_DFS_visit(Complement, VertexDecreasingF[i].second, color, discover, gcfinish, parent);
		writeToFile(path, outputfile, "append");
	}
}





