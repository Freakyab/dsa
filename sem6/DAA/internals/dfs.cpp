#include <iostream>
#include <cstring>

#define MAX_VERTICES 100

// Adjacency matrix representation of graph
int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int vertices;

// Depth First Search function
void dfs(int vertex) {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for (int i = 0; i < vertices; ++i) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    memset(graph, 0, sizeof(graph)); // Initialize graph to all zeros
    memset(visited, false, sizeof(visited)); // Initialize visited array to all false

    // Example graph
    vertices = 6;
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][5] = graph[5][3] = 1;

    std::cout << "DFS traversal starting from vertex 0: ";
    dfs(0); // Start DFS from vertex 0

    return 0;
}
