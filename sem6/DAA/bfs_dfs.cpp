#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int v) : V(v), adj(v) {}

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

   // Depth First Search
    void DFSUtil(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << current << " ";

        for (int v : adj[current]) {
            // cout<< "\t" << v <<" ";
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
            // cout << endl;
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
        cout << endl;
    }

    // Breadth First Search
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> queue;

        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();

            cout << current << " ";

            for (int v : adj[current]) {
                if (!visited[v]) {
                    visited[v] = true;
                    queue.push(v);
                }
            }
        }
        cout << endl;
    }
     void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << " :";
            for (int v : adj[i]) {
                cout << " -> " << v;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(7); // Create a graph with 5 vertices

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    g.printGraph();


    cout << "Depth First Search (DFS): ";
    g.DFS(0);

    cout << "Breadth First Search (BFS): ";
    g.BFS(0);

    return 0;
}
