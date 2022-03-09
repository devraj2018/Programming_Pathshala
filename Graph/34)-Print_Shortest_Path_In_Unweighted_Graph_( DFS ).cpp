
 
void dfs(vector<int>adj[],int src,int t,vector<int>&curr_path,vector<bool>&vis,int d,vector<int>&res,int &small)
{
     vis[src]=true;
     curr_path.push_back(src);
    
      if( src == t)
         {
             if(small==-1)
                {
                  small=d;
                 res=curr_path;
                }
             else if(d<small)
                {
                small=d;
               res=curr_path;
               }
            vis[src]=false;
            curr_path.pop_back();
           return;
        }
    for(auto x:adj[src])
    {
        if(!vis[x])
        {  
            dfs(adj,x,t,curr_path,vis,d+1,res,small);
        }
    }
    
    vis[src]=false;
    curr_path.pop_back();
    
}
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	vector<int>adj[n+1];
    
    for(int i=0;i<m;i++)
      {
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
    vector<int>curr_path;
    vector<bool>visited(n+1,false);
    
    int d=0;
    vector<int>res;
    int small=-1;
    dfs(adj,s,t,curr_path,visited,d,res,small);
    
    return res;
  	
}
