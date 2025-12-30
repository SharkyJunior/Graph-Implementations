#include "MatrixGraph.h"
#include <cassert>

MatrixGraph::MatrixGraph(int vertices_count) 
    : adjacency_matrix(vertices_count, std::vector<bool>(vertices_count, false)) {}

MatrixGraph::MatrixGraph(const IGraph& graph) 
    : adjacency_matrix(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), false)) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int vertex : graph.GetNextVertices(i)) {
            AddEdge(i, vertex);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacency_matrix.size());
    assert(to >= 0 && to < adjacency_matrix.size());
    adjacency_matrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(adjacency_matrix.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_matrix.size());
    std::vector<int> next_vertices;
    
    for (int to = 0; to < adjacency_matrix[vertex].size(); ++to) {
        if (adjacency_matrix[vertex][to]) {
            next_vertices.push_back(to);
        }
    }
    
    return next_vertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_matrix.size());
    std::vector<int> prev_vertices;
    
    for (int from = 0; from < adjacency_matrix.size(); ++from) {
        if (adjacency_matrix[from][vertex]) {
            prev_vertices.push_back(from);
        }
    }
    
    return prev_vertices;
}