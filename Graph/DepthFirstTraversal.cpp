#include<bits/stdc++.h>
#define V 7
using namespace std;
vector<int> adj[V];
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<bool> visited(V, false);
void depthFirstTraversal(int node){
    visited[node] = true;
    printf("%d ", node);
    for(auto i : adj[node]){
        if(!visited[i])
            depthFirstTraversal(i);
    }
}
int main(){
   
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    depthFirstTraversal(1);
}