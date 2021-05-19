#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void breadthFirstTraversal(vector<int> adj[], int V){
    queue<int> q;
    vector<bool> visited(V, false);
    q.push(6);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        visited[x] = true;
        printf("%d ",x);
        for(auto i : adj[x]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
void print(vector<int> adj[], int V){
    for(int u=1; u<V; u++){
        printf("Adjacency list for %d --> ",u);
        for(auto i : adj[u]){
            printf("%d, ",i);
        }
        printf("\n");
    }
    
}
int main(){
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 1,3);
    addEdge(adj, 1,2);
    addEdge(adj, 2,4);
    addEdge(adj, 2,5);
    addEdge(adj, 3,5);
    addEdge(adj, 4,5);
    addEdge(adj, 4,6);
    addEdge(adj, 5,6);
    print(adj, V);
    breadthFirstTraversal(adj, V);
       
}