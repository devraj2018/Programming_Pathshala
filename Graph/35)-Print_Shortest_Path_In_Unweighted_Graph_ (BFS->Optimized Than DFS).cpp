------------------------------------------------------------------------------------------------------------------------
------------------------------------------ Easy BFS Method ---------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	 
	
	  vector<int>adj[n+1];
	  for(int i=0;i<m;i++)
      {
        int u=edges[i].first;            // Build Graph
        int v=edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
	
	 vector<int>visited(n+1,0);
	 vector<int>parent(n+1);
	
	 queue<int>q;
	 q.push(s);
	 visited[s]=1;
	 parent[s]=-1;
	
	while(!q.empty())
	{
	   	int curr=q.front();q.pop();
	  	if(curr==t) break;
		
		  for(auto child:adj[curr])
		    {
			    if(visited[child]==0)
			      {
				     q.push(child);
				     visited[child]=1;
				     parent[child]=curr;
			     }
		 	 
		   }
 	}
	
	   vector<int>res;
	    while(t!=-1)
	      {
	    	 res.push_back(t);
		     t=parent[t];
	     }
	   reverse(res.begin(),res.end());
   	return res;
	 
	
}


------------------------------------------------------------------------------------------------------------
-----------------------------Word Ladder II Type Approach ---------------------------------------
------------------------------------------------------------------------------------------------------------

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
