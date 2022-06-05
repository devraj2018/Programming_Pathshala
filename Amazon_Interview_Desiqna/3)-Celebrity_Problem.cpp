=========================================================================================================
=====================    O(n) Time  && O(1)Space   ======================================================
=========================================================================================================
class Solution 
{
    public:
     
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        
         int a=0,b=n-1;
        
         while(a<b)
           {
            if(M[a][b]) a++;
            else b--;
          }
         int celeb=a;
        
         for(int i=0;i<n;i++)
           {
             if( i!=celeb && (M[i][celeb]==0 || M[celeb][i]==1)) return -1;
          }
        return celeb;
        
    }
};

=========================================================================================================
=====================    O(n*n) Time  && O(n)Space   ======================================================
===============================================================================================
             ========>>>>   indegree and outdegree Concept <<<==========
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
         
        int indegree[n]={0};
        int outdegree[n]={0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j])
                {
                    outdegree[i]++;
                    indegree[j]++;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==n-1 && outdegree[i]==0) return i;
        }
        return -1;
         
        
    }
};