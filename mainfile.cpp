#include <iostream>
#include <fstream>
#include <random>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;

static int ttime = 0;
void resetParameters(char * &color, int * &discover, int * &finish, int * &parent, int V);

#include "Graph.h"
#include "breadthFirstSearch.h"
#include "depthFirstSearch.h"
#include "fileIO.h"
#include "StronglyConnected.h"
#include "WeaklyConnected.h"
#include "BowTieStructure.h"


void resetParameters(char * &color, int * &discover, int * &finish, int * &parent, int V)
{
	for (int v = 0; v < V; v++)
	{
		color[v] = 'w';
		discover[v] = 0;
		finish[v] = 0;
		parent[v] = 0;
	}
	color[V] = '\0';
	ttime = 0;
}









int main()
{
	//Q1

	string filename = "SCC.txt";
	Graph graph(875714);
	graph.constructGraphfromFile(filename);


	int V = graph.getV();
	char * color = new char[V];
	int * discover = new int[V]();
	int * finish = new int[V]();
	int * parent = new int[V]();

	getStronglyConnected(graph, "q1output.txt", color, discover, finish, parent);


	//Q2

	//string filename = "epinions-network.txt";
	//Graph graph(75888);
	//graph.constructGraphfromFile(filename);

	//int V = graph.getV();
	//char * color = new char[V];
	//int * discover = new int[V]();
	//int * finish = new int[V]();
	//int * parent = new int[V]();

	//ComputeBowTieParameters(graph, color, discover, finish, parent);

//	SamplesAverage(graph, color, discover, finish, parent, 10);



	cin.clear();
	cin.ignore();
	cin.get();
	return 0;

}





