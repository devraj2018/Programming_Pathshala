class Solution 
{
    public:
   
    int celebrity(vector<vector<int> >& M, int n) 
    {
       int i=0,j=n-1;
        while(i<j)
          {
            if(M[i][j]==1) i++;
            else j--;
          }
       
         int person=i;
         for(int i=0;i<n;i++)
          {
           if(i!= person && (M[i][person]==0 || M[person][i]==1)) return -1;
          }
    
        return person;
    }
};