class Graph
{
public:
	vector<list<int>> * adj;
	int V;

	Graph(int N)
	{
		adj = new vector<list<int>>(N + 1);
		V = N;
	}
	Graph(vector<list<int>> * abc)
	{
		if (abc)
		{
			adj = abc;
			V = abc->size();
		}
	}
	void addEdge(int u, int v)
	{
		(*adj)[u].push_back(v);
	}
	void constructGraphfromFile(string filename)
	{
		ifstream myfile(filename);
		if (myfile.is_open())
		{
			int a = 0, b = 0, olda = 0;
			while (myfile >> a >> b)
			{
				addEdge(a, b);
			}
		}
	}
	list<int> getNeighbours(int v)
	{
		return (*adj)[v];
	}
	int getV()
	{
		return V;
	}

};
vector<list<int>> * getComplement(vector<list<int>> * adj)
{
	int V = adj->size();
	vector<list<int>> * complement = new vector<list<int> >(V);
	list<int> temp;
	list<int>::iterator it;
	for (int v = 0; v < V; ++v)
	{
		temp = (*adj)[v];
		for (it = temp.begin(); it != temp.end(); ++it)
		{
			(*complement)[*it].push_back(v);	//v added in list of *it
		}
	}
	return complement;
}
vector<list<int>> * GetBidirectional(vector<list<int>> * adj)
{
	vector<list<int>> * newadj(adj);
	vector<list<int>> * complement(getComplement(adj));
	list<int> temp, ctemp;
	list<int>::iterator it, cit;
	int V = adj->size();
	for (int v = 1; v < V; ++v)
	{
		temp = (*newadj)[v];
		ctemp = (*complement)[v];
		for (cit = ctemp.begin(); cit != ctemp.end(); ++cit)
		{
			if (find(temp.begin(), temp.end(), *cit) != temp.end()) {/* newadj contains *cit */ }
			else
			{
				/* newadj does not contain *cit */
				(*newadj)[v].push_back(*cit);
			}
		}
	}
	return newadj;
}
void printGraph(vector<list<int>> * adj)
{
	int V = adj->size();
	list<int> temp;
	list<int>::iterator it;

	for (int v = 1; v < V; ++v)
	{
		cout << "Adj List of " << v << endl;
		temp = (*adj)[v];
		for (it = temp.begin(); it != temp.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
}