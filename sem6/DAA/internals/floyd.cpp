// #include <iostream>
// #include <climits>

// using namespace std;

// #define V 4 // Number of vertices

// // Function to print the solution matrix
// void printSolution(int dist[][V]) {
//     cout << "Shortest distances between every pair of vertices:\n";
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             if (dist[i][j] == INT_MAX)
//                 cout << "INF\t";
//             else
//                 cout << dist[i][j] << "\t";
//         }
//         cout << endl;
//     }
// }

// // The main function that finds the shortest distances between every pair of vertices using Floyd-Warshall algorithm
// void floydWarshall(int graph[][V]) {
//     int dist[V][V];

//     // Initialize the distance matrix
//     for (int i = 0; i < V; i++)
//         for (int j = 0; j < V; j++)
//             dist[i][j] = graph[i][j];

//     // Add all vertices one by one to the set of intermediate vertices
//     for (int k = 0; k < V; k++) {
//         // Pick all vertices as source one by one
//         for (int i = 0; i < V; i++) {
//             // Pick all vertices as destination for the above picked source
//             for (int j = 0; j < V; j++) {
//                 // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
//                 if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
//                     dist[i][j] = dist[i][k] + dist[k][j];
//             }
//         }
//     }

//     // Print the shortest distances matrix
//     printSolution(dist);
// }

// int main() {
//     /* Let us create the following weighted graph
//            10
//       (0)------->(3)
//        |         /|\
//      5 |          |
//        |          | 1
//       \|/         |
//       (1)------->(2)
//           3           */
//     int graph[V][V] = {{0, 5, INT_MAX, 10},
//                        {INT_MAX, 0, 3, INT_MAX},
//                        {INT_MAX, INT_MAX, 0, 1},
//                        {INT_MAX, INT_MAX, INT_MAX, 0}};

//     // Print the solution
//     floydWarshall(graph);
//     return 0;
// }

#include <iostream>
#include <climits>
using namespace std;

#define v 4

int floyd(int graph[v][v])
{
    int dist[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            for (int k = 0; k < v; k++)
            {
               if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k]+dist[k][j] < dist[i][j]){
                dist[i][j] = dist[i][k]+dist[k][j];
               }
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
           if(dist[i][j] == INT_MAX){
            cout << "INF" << "\t";
           }else{
            cout << dist[i][j] <<"\t";
           }
        }
        cout << endl;
    }
}
int main()
{

    int graph[v][v] = {{0, 3, INT_MAX, 7},
                       {8, 0, 2, INT_MAX},
                       {5, INT_MAX, 0, 1},
                       {2, INT_MAX, INT_MAX, 0}};

    floyd(graph);
}
