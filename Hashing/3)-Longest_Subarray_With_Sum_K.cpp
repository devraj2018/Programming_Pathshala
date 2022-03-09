class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int,int>mp;
         mp[0]=-1;
        int curr_sum=0;
        int maxx=0;
        for(int i=0;i<N;i++)
        {    curr_sum+= A[i];
              if(mp.find(curr_sum - K)!=mp.end())
               {
                  maxx=max(maxx,i- mp[curr_sum - K]);
                //  cout<<mp[curr_sum - K]<<" "<<i<<endl;  // Debugging Step
               }
             
              if(mp.find(curr_sum )==mp.end())
                 mp[curr_sum]=i;
        }
       
        return maxx;
    } 

};