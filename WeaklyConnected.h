void getWeaklyConnected(Graph graph, string outputfile, char * &color, int * &discover, int * &finish, int * &parent)
{
	vector<list<int>> * bidirectional = GetBidirectional(graph.adj);
	Graph BiDirectional(bidirectional);
	int V = graph.getV();
	vector<vector<int>> paths = DFS(graph, V, color, discover, finish, parent);
	writePathsToFile(paths, outputfile);
}
