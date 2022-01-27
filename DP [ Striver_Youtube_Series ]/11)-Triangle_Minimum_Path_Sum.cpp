int minimumPathSum(vector<vector<int>>& triangle, int n){
	
    if(n==0) return 0;
    if(n==1) return triangle[0][0];
    
    for(int i=1;i<n;i++)
    {
         for(int j=0;j<triangle[i].size();j++)
         {
              if(j==0)
              {
                  triangle[i][j]+=triangle[i-1][j];
              }
              else if(j==triangle[i].size()-1)
              {
                   triangle[i][j]+= triangle[i-1][j-1];
              }
             else
                  triangle[i][j]+= min(triangle[i-1][j],triangle[i-1][j-1]);
             
         }
     }
    int ans=1e9;
    for(int j=0;j<triangle[n-1].size();j++)
    {
        ans=min(ans, triangle[n-1][j]);
    }
    return ans;
    
}