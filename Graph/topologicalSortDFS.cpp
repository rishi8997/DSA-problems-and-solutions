#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(int node, vector<int> &visited, stack<int> &s, vector<int> adj[])
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, visited, s, adj);
        }
    }
    s.push(node);
}
void topologicalSort(vector<int> adj[], int nodes)
{
    vector<int> visited(nodes, 0);
    stack<int> s;
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, s, adj);
        }
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
int main()
{
    int nodes, edges;
    int u, v;
    cin>>nodes>>edges;
    vector<int> adj[nodes];
    for (int i = 0; i < nodes; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topologicalSort(adj, nodes);
}