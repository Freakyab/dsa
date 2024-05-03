#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{
    int src, dest,weight;
};


class Graph{
    int V,E;
    Edge* edge;
    public:
        Graph(int v,int e){
            V = v;
            E = e;
            edge = new Edge[e];
        }

        ~Graph(){
            delete[] edge;
        }

        void addEdge(int src,int dest,int weight){
            static int i = 0;
            edge[i].src = src;
            edge[i].dest = dest;
            edge[i].weight = weight;
            i++;
        }

        int find(int parent[],int i){
            if(parent[i] != i)
                parent[i] = find(parent,parent[i]);
            return parent[i];
        }

        int Union(int parent[],int rank[], int x,int y){
            int xroot = find(parent,x);
            int yroot = find(parent,y);

            if(parent[xroot] < rank[yroot]){
                parent[xroot] = yroot;
            }
            else if(parent[xroot] > rank[yroot])
                parent[yroot] = xroot;
            else {
                parent[yroot] = xroot;
                rank[xroot]++;
            }
        }

        void Kruskal() {
            Edge result[V];
            int e = 0, i =0;

            sort(edge,edge+E,[](Edge a,Edge b){
                return a.weight < b.weight;
            });

            int *parent = new int[V];
            int *rank = new int[V];

            for(int v=0; v<V;v++){
                parent[v] = v;
                rank[v] = 0;
            }

            while(e <V-1 && i < E ){
                Edge next_Edge = edge[i++];
                int x = find(parent,next_Edge.src);
                int y = find(parent,next_Edge.dest);

                if(x != y) {
                    result[e++] = next_Edge;
                    Union(parent,rank,x,y);
                }
            }
            for(int i = 0; i<e;i++){
                cout << result[i].src << "-" <<result[i].dest <<endl;
            }

            delete[] parent;
            delete[] rank;

        }
};

int main()
{
    int V = 6;  // Number of vertices
    int E = 19; // Number of edges

    Graph g(V, E);




    // Add edges
    g.addEdge(0,2,8);
    g.addEdge(0,1,7);
    g.addEdge(1,4,5);
    g.addEdge(1,3,6);
    g.addEdge(1,2,3);
    g.addEdge(1,0,7);
    g.addEdge(2,4,3);
    g.addEdge(2,3,4);
    g.addEdge(2,1,3);
    g.addEdge(2,0,8);
    g.addEdge(3,5,5);
    g.addEdge(3,4,2);
    g.addEdge(3,2,4);
    g.addEdge(3,1,6);
    g.addEdge(4,5,2);
    g.addEdge(4,3,2);
    g.addEdge(4,2,3);
    g.addEdge(4,1,5);
    g.addEdge(5,4,2);
    g.addEdge(5,3,5);

    // Find Minimum Spanning Tree
    g.Kruskal();

    return 0;
}
