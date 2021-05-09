#include <iostream>
#include "Graph.h"
#include "algorithm_on_graph.h"

using namespace std;

int main()
{
	vector <bool> used;
	int start;

	cout << "graph:" << endl;
	Graph graph;
	graph.input();
	graph.print();
	cin >> start;
	cout << "DFS: ";
	used.resize(graph.getVertexesNumber(), false);
	DFS(graph, start, used);
	cout << endl << "BFS: ";
	BFS(graph, start);

	cout << endl << endl << "orgraph:" << endl;
	OrGraph orgraph;
	orgraph.input();
	orgraph.print();
	(DAG(orgraph)) ? cout << "acycle graph" << endl : cout << "cycle graph" << endl;
	cin >> start;
	cout << "DFS: ";
	used.clear();
	used.resize(orgraph.getVertexesNumber(), false);
	DFS(orgraph, start, used);
	cout << endl << "BFS: ";
	BFS(orgraph, start);
	cout << endl;

    return 0;
}