#pragma once
#include "IGraph.h"
#include <vector>
#include <utility>

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int vertices_count);
    explicit ArcGraph(const IGraph& graph);
    
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int vertices_count;
    std::vector<std::pair<int, int>> edges;
};