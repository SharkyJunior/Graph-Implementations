#include "ArcGraph.h"
#include <cassert>

ArcGraph::ArcGraph(int vertices_count) 
    : vertices_count(vertices_count) {}

ArcGraph::ArcGraph(const IGraph& graph) 
    : vertices_count(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int vertex : graph.GetNextVertices(i)) {
            AddEdge(i, vertex);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < vertices_count);
    assert(to >= 0 && to < vertices_count);
    edges.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return vertices_count;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count);
    std::vector<int> next_vertices;
    
    for (const auto& [from, to] : edges) {
        if (from == vertex) {
            next_vertices.push_back(to);
        }
    }
    
    return next_vertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count);
    std::vector<int> prev_vertices;
    
    for (const auto& [from, to] : edges) {
        if (to == vertex) {
            prev_vertices.push_back(from);
        }
    }
    
    return prev_vertices;
}