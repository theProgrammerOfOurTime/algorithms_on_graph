#pragma once
#include "Graph.h"
#include <vector>
#include <iostream>
#include <deque>

bool DAG(OrGraph);

template <class graph>
void DFS(graph g, abstractGraph::vertex_t start, std::vector<bool>& used)
{
	std::cout << start << " ";
	used[start] = true;
	for (auto neighbour : g.list[start])
	{
		if (used[neighbour] == false) { DFS(g, neighbour, used); }
	}
	return;
}

template <class graph>
void BFS(graph g, abstractGraph::vertex_t start)
{
	std::vector<bool> used(g.getVertexesNumber());
	std::deque <abstractGraph::vertex_t> usings;
	used[start] = true;
	usings.push_back(start);
	while (usings.empty() == false)
	{
		abstractGraph::vertex_t current = usings.front();
		usings.pop_front();
		std::cout << current << " ";
		for (auto neighbour : g.list[current])
		{
			if (used[neighbour] == false)
			{
				used[neighbour] = true;
				usings.push_back(neighbour);
			}
		}
	}
	std::cout << std::endl;
	return;
}