#include "SetGraph.h"
#include <cassert>

SetGraph::SetGraph(int vertices_count) 
    : adjacency_sets(vertices_count) {}

SetGraph::SetGraph(const IGraph& graph) 
    : adjacency_sets(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int vertex : graph.GetNextVertices(i)) {
            AddEdge(i, vertex);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacency_sets.size());
    assert(to >= 0 && to < adjacency_sets.size());
    adjacency_sets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(adjacency_sets.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_sets.size());
    return std::vector<int>(adjacency_sets[vertex].begin(), adjacency_sets[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_sets.size());
    std::vector<int> prev_vertices;
    
    for (int from = 0; from < adjacency_sets.size(); ++from) {
        if (adjacency_sets[from].count(vertex) > 0) {
            prev_vertices.push_back(from);
        }
    }
    
    return prev_vertices;
}