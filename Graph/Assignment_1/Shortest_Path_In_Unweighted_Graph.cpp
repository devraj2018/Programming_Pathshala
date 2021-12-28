#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int size;
        vector<int> *adj;
        Graph(int n) {
            size=n;
            adj=new vector<int>[n+1];
        }
    
        void add_edge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            vector<int>res(size,-1);
            bool first=true;
            vector<bool> vis(size+1,false);
            queue<pair<int,int>>q;
            q.push({start,0});
            vis[start]=true;
            while(!q.empty())
            {
                 int curr_node=q.front().first;
                 int curr_dis=q.front().second;
                 q.pop();
                 
                 if(!first)
                 {
                   res[curr_node]=curr_dis;
                 }
                 first=false;
                 
                 for(auto x:adj[curr_node])
                 {
                      if(!vis[x])
                      {
                          vis[x]=true;
                          q.push({x,curr_dis+6});
                      }
                      
                 }
            }
            return res;
             
            
            
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}