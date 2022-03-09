
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	 vector<int>adj[n+1];
     for(int i=0;i<m;i++)
        {
         int u=edges[i].first;
         int v=edges[i].second;
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
    
       vector<bool>vis(n+1,false);
       queue<pair<int,vector<int>>>q;
       q.push({s,{s}});
       vis[s]=true;
       while(!q.empty())
           {
              int size=q.size();
              for(int i=0;i<size;i++)
                  {
                      int curr=q.front().first;
                      vector<int>path=q.front().second;
                      q.pop();

                     if(curr==t) return path; 
           
                     for(auto child: adj[curr])
                       {
                           if(!vis[child])
                              {    path.push_back(child);
                                   vis[child]=true;
                                   q.push({child,path});
                                   path.pop_back();   // This step is very Important
                              }
                
                        }
                
                   }
           
           }
    
     return {};
  	
}
