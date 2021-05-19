#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool bfs(int node, vector<int> &colored, vector<int> adj[])
{
    queue<int> q;
    colored[node] = 0;
    q.push(node);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto it : adj[temp])
        {
            if (colored[it] == -1)
            {
                colored[it] = !colored[temp];
                q.push(it);
            }
            else if (colored[it] == colored[temp])
                return false;
        }
    }
    return true;
}
bool checkBipartite(vector<int> adj[], int nodes)
{
    vector<int> colored(nodes, -1);
    for (int i = 1; i <= nodes; i++)
    {
        if (colored[i] == -1)
        {
            if (bfs(i, colored, adj))
                return true;
        }
    }
    return false;
}
int main()
{
    int u, v, nodes, edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes + 1]; //adjacency list
    for (int i = 1; i <= edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = checkBipartite(adj, nodes);
    if (ans)
        cout << "Bipartite" << endl;
    else
        cout << "Non Bipartite" << endl;
}