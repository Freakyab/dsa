// #include <bits/stdc++.h>

// using namespace std;

// #define V 6

// int minKey(int key[], bool mstSet[])
// {
//     int min = INT_MAX, min_index;
//     for (int v = 0; v < V; v++)
//     {
//         if (!mstSet[v] && key[v] < min)
//         {
//             min = key[v];
//             min_index = v;
//         }
//     }
//     return min_index;
// }

// void Print(int parent[], int graph[V][V])
// {
//     cout << "Edge \tWeight\n";
//     for (int i = 1; i < V; i++)
//         cout << parent[i] << "-" << i << "\t" << graph[i][parent[i]] << endl;
// }

// void prism(int graph[V][V])
// {
//     int parent[V], key[V];
//     bool mstSet[V];

//     for (int i = 0; i < V; i++)
//     {
//         key[i] = INT_MAX;
//         mstSet[i] = false;
//     }

//     key[0] = 0;
//     parent[0] = -1;

//     for (int v = 0; v < V - 1; v++)
//     {
//         int u = minKey(key, mstSet);
//         mstSet[u] = true;

//         for (int k = 0; k < V; k++)
//         {
//             if (graph[u][k] && !mstSet[v] && graph[u][k] < key[k])
//             {
//                 parent[k] = u;
//                 key[k] = graph[u][k];
//             }
//         }
//     }

//     Print(parent,graph);
// }

// int main() {
//     /* Example graph:
//         2    3
//     (0)--(1)--(2)
//      |   / \   |
//     6| 8/   \5 |7
//      | /     \ |   2
//     (3)-------(4)------(5)
//           9         */
//     int graph[V][V] = {{0, 2, 0, 6, 0, 0},
//                        {2, 0, 3, 8, 5, 0},
//                        {0, 3, 0, 0, 7, 0},
//                        {6, 8, 0, 0, 9, 0},
//                        {0, 5, 7, 9, 0, 2},
//                        {0, 0, 0, 0, 2, 0}};

//     // Print the MST
//     prism(graph);

//     return 0;
// }

#include <bits\stdc++.h>

using namespace std;

int print(int arr[], int n, int pivot)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\t" << pivot;
    cout << endl;
}

int partition(int arr[], int l, int h, int n)
{
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            print(arr, n, pivot);
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

int QuickSort(int arr[], int low, int high, int n)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high, n);
        QuickSort(arr, low, pivot - 1, n);
        QuickSort(arr, pivot + 1, high, n);
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, n, n);
    print(arr, n, -1);
}