#include <bits/stdc++.h>

using namespace std;

void DFS(int start, vector<vector<int>> &adjList, vector<bool> &visited){
    visited[start] = true;
    cout << start << " ";

    for(int n : adjList[start]){
        if(!visited[n]){
            DFS(n,adjList,visited);
        }
    }
}

int main(){
    int n =6;
    vector<vector<int>> adjList(n);
    vector<bool> visited(n,false);

    adjList[0] = {1,2};
    adjList[1] = {0,3,4};
    adjList[2] = {0,5};
    adjList[3] = {1};
    adjList[4] = {1};
    adjList[5] = {2};

    DFS(0,adjList,visited);
}