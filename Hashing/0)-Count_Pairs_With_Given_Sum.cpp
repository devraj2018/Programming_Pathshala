class Solution
{
    public:
    
    int countKdivPairs(int arr[], int n, int k)
    {   int ans=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)
          {
              if(mp.find((k- arr[i]%k)%k)!=mp.end())
               {
                 ans+= mp[(k-arr[i]%k)%k];
               }
             mp[arr[i]%k]++;
         }
        return ans;
    }
};