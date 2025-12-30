#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void PrintGraphInfo(const IGraph& graph, const std::string& name) {
    std::cout << "=== " << name << " ===" << std::endl;
    std::cout << "Vertices: " << graph.VerticesCount() << std::endl;
    
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        std::cout << "Vertex " << i << ": ";
        std::cout << "next -> ";
        for (int v : graph.GetNextVertices(i)) {
            std::cout << v << " ";
        }
        std::cout << "| prev <- ";
        for (int v : graph.GetPrevVertices(i)) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    ListGraph list_graph(5);
    list_graph.AddEdge(0, 1);
    list_graph.AddEdge(0, 2);
    list_graph.AddEdge(1, 2);
    list_graph.AddEdge(2, 3);
    list_graph.AddEdge(3, 4);
    list_graph.AddEdge(4, 0);
    
    MatrixGraph matrix_graph(list_graph);
    SetGraph set_graph(list_graph);
    ArcGraph arc_graph(list_graph);
    
    PrintGraphInfo(list_graph, "ListGraph");
    PrintGraphInfo(matrix_graph, "MatrixGraph");
    PrintGraphInfo(set_graph, "SetGraph");
    PrintGraphInfo(arc_graph, "ArcGraph");
    
    return 0;
}