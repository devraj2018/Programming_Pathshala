class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       int a=0;int b=n-1;
       
        while(a<b)
          {
            if(M[a][b]) a++;         // if a knows b then a  definitely will not be celebrity
            else b--;
         }
       
       for(int i=0;i<n;i++)
       {
            if((i!=a) &&( M[a][i]==1 || M[i][a]==0))
            return -1;
           
       }
       return a;
       
    }
    
};