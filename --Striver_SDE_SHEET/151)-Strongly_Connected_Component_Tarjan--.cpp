#include<bits/stdc++.h>
void dfsSort(int node, vector<int> adj[], vector<int>& vis, stack<int>& st)
{
    for(int adjNode: adj[node])
    {
        if(!vis[adjNode]){
            vis[adjNode]=1;
            dfsSort(adjNode, adj, vis,st );
        }
    }
    st.push(node);
}
void revDFS(int node, vector<int>& vis, vector<int> adj[], vector<int>& comp)
{
    vis[node]=1;
    comp.push_back(node);
    for(int adjNode: adj[node]){
        if(!vis[adjNode])
        {
            revDFS(adjNode, vis, adj, comp);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    vector<int> vis(n, 0);
    vector<int> trans[n];
    stack<int> st;
    for(auto edge: edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    //sort nodes based on finish time
    for(int i=0; i<n; i++)
    {
        if(!vis[i]){
            vis[i]=1;
            dfsSort(i, adj, vis, st);
        }
    }
    //form a transporse graph
    for(int i=0; i<n; i++)
    {
        vis[i]=0;
        for(int node: adj[i]){
            trans[node].push_back(i);
        }
    }
    //reverse dfs
    //based on finish time nodes are sorted and stored in stack, 
    //and based on that sorted order, dfs traversal is called.
    vector<vector<int>> res;
    while(!st.empty())
    {
        int i=st.top();
        st.pop();
        if(!vis[i]){
            vector<int> comp;
            revDFS(i, vis, trans, comp);
            res.push_back(comp);
        }      
    }
    return res;
}