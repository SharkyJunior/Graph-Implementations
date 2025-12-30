#include "ListGraph.h"
#include <cassert>

ListGraph::ListGraph(int vertices_count) 
    : adjacency_lists(vertices_count) {}

ListGraph::ListGraph(const IGraph& graph) 
    : adjacency_lists(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int vertex : graph.GetNextVertices(i)) {
            AddEdge(i, vertex);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacency_lists.size());
    assert(to >= 0 && to < adjacency_lists.size());
    adjacency_lists[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(adjacency_lists.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_lists.size());
    return std::vector<int>(adjacency_lists[vertex].begin(), adjacency_lists[vertex].end());
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_lists.size());
    std::vector<int> prev_vertices;
    
    for (int from = 0; from < adjacency_lists.size(); ++from) {
        for (int to : adjacency_lists[from]) {
            if (to == vertex) {
                prev_vertices.push_back(from);
                break;
            }
        }
    }
    
    return prev_vertices;
}