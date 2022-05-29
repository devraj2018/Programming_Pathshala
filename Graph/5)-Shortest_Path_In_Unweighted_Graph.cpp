vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	  vector<int>adj[n+1];
	
	for(int i=0;i<m;i++)
	{
		  adj[edges[i].first].push_back(edges[i].second);
		  adj[edges[i].second].push_back(edges[i].first);
	}
	
	queue<int>q;
	q.push(s);
	vector<int>visited(n+1,0);
	visited[s]=1;
	vector<int>par(n+1);
	par[s]=-1;
	
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		
		if(curr==t) break;
		
		
		for(auto child:adj[curr])
		{
			if(visited[child]==0)
			{
				visited[child]=1;
				q.push(child);
				par[child]=curr;
				
			}
		}
		  
	}
	
	vector<int>res;
	
	while(t!=-1)
	{
		res.push_back(t);
		t=par[t];
	}
	reverse(res.begin(),res.end());
	return res;
	

	
}