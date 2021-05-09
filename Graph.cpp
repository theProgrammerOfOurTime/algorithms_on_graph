#include "Graph.h"
#include <iostream>

void abstractGraph::print() const
{
	std::cout << "Vertexes number = " << vertexes_number << std::endl;
	for (auto vertex : list)
	{
		std::cout << vertex.vertex_number << ": {";
		for (auto adjacent_vertex : vertex.list_of_adjecency)
		{
			std::cout << adjacent_vertex << ", ";
		}
		std::cout << "\b\b}" << std::endl;
	}
}

abstractGraph::vertex_t abstractGraph::getVertexesNumber()
{
	return vertexes_number;
}

void OrGraph::input()
{
	std::cin >> vertexes_number;
	std::cin >> edges_number;
	list.clear();
	for (int i = 0; i < edges_number; i++)
	{
		vertex_t a, b;
		std::cin >> a >> b;
		list[a].insert(b);
	}
}

void Graph::input()
{
	std::cin >> vertexes_number;
	std::cin >> edges_number;
	list.clear();
	for (int i = 0; i < edges_number; i++)
	{
		vertex_t a, b;
		std::cin >> a >> b;
		list[a].insert(b);
		list[b].insert(a);
	}
}