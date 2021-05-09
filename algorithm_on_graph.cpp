#include "algorithm_on_graph.h"
#include <vector>
#include <iostream>

bool check_DAG(OrGraph, OrGraph::vertex_t, std::vector<bool>&);

bool DAG(OrGraph graph)
{
	std::vector <bool> used(graph.getVertexesNumber());
	for (int i = 0; i < graph.getVertexesNumber(); i++)
	{
		if (used[i]) { continue; }
		if (!check_DAG(graph, i, used)) { return false; }
	}
	return true;
}

bool check_DAG(OrGraph graph, OrGraph::vertex_t start, std::vector<bool>& used)
{
	used[start] = true;
	for (auto neighbour : graph.list[start])
	{
		if (used[neighbour]) { return false; }
		if (!check_DAG(graph, neighbour, used)) { return false; }
	}
	return true;
}