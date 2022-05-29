class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
       int curr_sum=0;
       unordered_map<int,int>mp;
       mp[0]++;
       for(int i=0;i<n;i++)
       { curr_sum+=arr[i];
            if(mp.find(curr_sum)!=mp.end())
             return true;
            mp[curr_sum]++;
           
       }

       return false;
       
    }
};