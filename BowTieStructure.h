int sampleSCC(Graph graph, char * &color, int * &discover, int * &finish, int * &parent, vector<int>scc, string mode)
{
	vector<list<int>> * complement = NULL;
	if (mode == "in")
		complement = getComplement(graph.adj);
	Graph Complement(complement);
	int v = -1;
	vector<int> path;
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, scc.size()); // define the range
	v = scc.at(distr(eng));
	resetParameters(color, discover, finish, parent, graph.getV());
	path.clear();
	if (mode == "in")
		path = iterative_BFS_visit(Complement, v, color, discover, finish, parent);
	else
		path = iterative_BFS_visit(graph, v, color, discover, finish, parent);
	cout << " StartVertex: " << v << " Reachable: " << path.size() << endl;
	return path.size();
}
void ComputeBowTieParameters(Graph graph, char * &color, int * &discover, int * &finish, int * &parent)
{
	int in = 0, out = 0, tendrils_tubes = 0, disconnected = 0, scc = 0, connected = 0;

	resetParameters(color, discover, finish, parent, graph.getV());
	cout << "Computing SCC.." << endl;
	getStronglyConnected(graph, "q2strcc.txt", color, discover, finish, parent);
	vector<int> largestSCC = getLargestComponent("q2strcc.txt");
	scc = largestSCC.size();
	cout << "Writing largest SCC to file.." << endl;
	writeToFile(largestSCC, "largestSCC.txt", "new");

	vector<int> strcc = getSCCfromFile("largestSCC.txt");
	cout << "Running BFS on vertex in SCC on graph.." << endl;
	resetParameters(color, discover, finish, parent, graph.getV());
	out = sampleSCC(graph, color, discover, finish, parent, strcc, "out") - scc;


	cout << "Running BFS on vertex in SCC on complement.." << endl;
	resetParameters(color, discover, finish, parent, graph.getV());
	in = sampleSCC(graph, color, discover, finish, parent, strcc, "in") - scc;

	cout << "Computing Weakly connected components.." << endl;
	resetParameters(color, discover, finish, parent, graph.getV());
	getWeaklyConnected(graph, "q2wcc.txt", color, discover, finish, parent);

	cout << "Writing largest WCC to file.." << endl;
	vector<int> largestConnectedComp = getLargestComponent("q2wcc.txt");
	connected = largestConnectedComp.size();

	tendrils_tubes = connected - (scc + in + out);
	disconnected = graph.getV() - connected;

	cout << "Writing BowTie components to file.." << endl;
	ofstream BowTie("BowTie.txt");
	if (BowTie.is_open())
	{
		BowTie << "SCC:" << scc << endl
			<< "IN:" << in << endl
			<< "OUT:" << out << endl
			<< "TENDRIL+TUBES:" << tendrils_tubes << endl
			<< "DISCONNECTED:" << disconnected << endl;
	}
	cout << "SCC:" << scc << endl
		<< "IN:" << in << endl
		<< "OUT:" << out << endl
		<< "TENDRIL+TUBES:" << tendrils_tubes << endl
		<< "DISCONNECTED:" << disconnected << endl;
}
int randomlySampleDataPoints(Graph graph, char * &color, int * &discover, int * &finish, int * &parent, int totalsamples = 10)
{
	resetParameters(color, discover, finish, parent, graph.getV());
	int v = -1, reached = 0;
	vector<int> total_reached, temp;
	vector<int>::iterator it;
	for (int i = 0; i < totalsamples; ++i)
	{
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 eng(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, graph.getV()); // define the range
		v = distr(eng);
		temp = iterative_BFS_visit(graph, v, color, discover, finish, parent);
		for (it = temp.begin(); it != temp.end(); ++it)
		{
			if (std::find(total_reached.begin(), total_reached.end(), *it) == total_reached.end())
			{
				total_reached.push_back(*it);
			}
		}
		temp.clear();
	}
	reached = total_reached.size();
	cout << "Sampled: " << totalsamples << " Reached: " << reached << endl;
	return reached;
}
void SamplesAverage(Graph graph, char * &color, int * &discover, int * &finish, int * &parent, int totalsamples = 10)
{
	vector<int>temp;
	for (int i = 0; i < 10; i++)
	{
		temp.push_back(randomlySampleDataPoints(graph, color, discover, finish, parent, totalsamples));
	}
	ofstream rS("randomSampled.txt");
	if (rS.is_open())
	{
		vector<int>::iterator it;
		for (it = temp.begin(); it != temp.end(); ++it)
			rS << "No. sampled:" << totalsamples << " Reached: " << *it << endl;
		rS << "No. sampled:" << totalsamples << " Avg Reached: " << accumulate(temp.begin(), temp.end(), 0.0) / temp.size() << endl;
	}
}
