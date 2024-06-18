#include <bits/stdc++.h>

using namespace std;

void BFS(int start, vector<vector<int>> &adjList){
    vector<bool> visited(adjList.size(),false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        cout << node << " ";
        q.pop();

        for(int n:adjList[node]){
            if(!visited[n]){
                visited[n] =  true;
                q.push(n);
            }
        }
    }
}
int main(){
    int n =6;
    vector<vector<int>> adjList(n);

    adjList[0] = {1,2};
    adjList[1] = {0,3,4};
    adjList[2] = {0,5};
    adjList[3] = {1};
    adjList[4] = {1};
    adjList[5] = {5};

    BFS(0,adjList);
}

