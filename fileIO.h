vector<int> getLargestComponent(string sccfile)
{
	vector<int> largestSCC;
	ifstream myfile(sccfile);
	int a = -1, b = -1, largest = 0;
	char * sz = new char[5];
	char * arrow = new char[2];
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile >> sz >> a >> arrow >> b;
			if (largest < a)
			{
				largestSCC.clear();
				largestSCC.push_back(b);
				for (int i = 1; i < a; i++)
				{
					myfile >> arrow >> b;;
					largestSCC.push_back(b);
				}
				largest = a;
			}
			else if (a > 1)
			{
				for (int i = 1; i < a; i++)
					myfile >> arrow >> b;;
			}
			cout << "sz:" << sz << " " << a << " " << arrow << b << endl;
		}
	}
	return largestSCC;
}
void writeToFile(vector<int>path, string outputfile, string mode)
{
	ofstream outfile;
	if (mode == "append")
		outfile.open(outputfile, std::ios_base::app);// if we want to append to existing file //outfile.open("output.txt", std::ios_base::app);
	else if (mode == "new")
		outfile.open(outputfile);
	vector<int>::iterator it;
	if (path.begin() != path.end())
	{
		for (it = path.begin(); it != path.end(); ++it)
		{
			if (it != path.begin())
				outfile << ", ";
			else
				outfile << "Size: " << path.size() << " => ";
			outfile << *it;
		}
		outfile << endl;
	}

}
vector<int> getSCCfromFile(string sccfile)
{
	vector<int> SCCvec;
	ifstream scc(sccfile);
	char* sz = new char[5];
	char* arrow = new char[2];
	int size, b;
	if (scc.is_open())
	{
		scc >> sz >> size >> arrow >> b;
		SCCvec.push_back(b);
		for (int i = 1; i < size; i++)
		{
			scc >> arrow >> b;
			SCCvec.push_back(b);
		}
	}
	return SCCvec;
}
void writePathsToFile(vector<vector<int>>paths, string outputfile)
{
	vector<vector<int>>::iterator pit;
	vector<int> path;
	vector<int>::iterator it;
	ofstream outfile(outputfile);
	if (outfile.is_open())
	{
		for (pit = paths.begin(); pit != paths.end(); ++pit)
		{
			path = *pit;
			for (it = path.begin(); it != path.end(); ++it)
			{
				if (it != path.begin())
				{
					cout << "->";
					outfile << ", ";
				}
				else
				{
					cout << "Size: " << path.size() << " => ";
					outfile << "Size: " << path.size() << " => ";
				}
				cout << *it;
				outfile << *it;
			}
			cout << endl;
			outfile << endl;
		}
	}
}
