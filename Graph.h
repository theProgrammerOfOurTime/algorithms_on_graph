#pragma once
#include <set>
#include <map>
#include <vector>

class abstractGraph
{
protected:
	typedef int32_t vertex_t;
	int vertexes_number, edges_number;
	#define vertex_number first
	#define list_of_adjecency second
	std::map <vertex_t, std::set<vertex_t>> list; //list of adjecency
public:
	abstractGraph() : vertexes_number(0), edges_number(0) {}
	virtual void input() = 0;
	void print() const;
	vertex_t getVertexesNumber();
	template <class graph>
	friend void DFS(graph, abstractGraph::vertex_t, std::vector<bool>&);
	template <class graph>
	friend void BFS(graph, abstractGraph::vertex_t);
};

class OrGraph : public abstractGraph
{
public:
	OrGraph() : abstractGraph() {}
	void input() override;
	friend bool DAG(OrGraph);
	friend bool check_DAG(OrGraph, vertex_t, std::vector<bool>&);
};

class Graph : public abstractGraph
{
public:
	Graph() : abstractGraph() {}
	void input() override;
};