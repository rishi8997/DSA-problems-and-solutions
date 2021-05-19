//To detect whether there is a cycle in a directed graph
#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node, vector<int> visited, vector<int> dfsVisited, vector<int> adj[]){
    visited[node] = 1;
    dfsVisited[node] = 1;
    for(auto it : adj[node]){
        if(visited[it]==0){
            if(dfs(it, visited, dfsVisited, adj)) return true; 
        }
        else if(dfsVisited[it] == 1) return true;
    }
    dfsVisited[node] = 0;
    return false;
}

bool isCycle(vector<int> adj[], int nodes){
    vector<int> visited(nodes, 0);
    vector<int> dfsVisited(nodes, 0);
    for(int i=1; i<=nodes; i++){
        if(visited[i]==0){
            if(dfs(i, visited, dfsVisited, adj)) return true;
        }
    }
    return false;
}

int main(){
    int nodes, edges;
    int u,v;
    cin>>nodes>>edges;
    vector<int> adj[nodes+1];
    for(int i=1; i<=edges; i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    if(isCycle(adj, nodes)) cout<<"Cycle is present";
    else cout<<"Cycle not present";
}