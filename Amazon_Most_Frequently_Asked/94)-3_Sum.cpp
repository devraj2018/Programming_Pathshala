class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
             int j=i+1,k=n-1;
            
             while(j<k)
             {
                 
                 if(nums[i]+nums[j]+nums[k]>0) k--;
                 else if(nums[i]+nums[j]+nums[k]<0) j++;
                 else
                 {
                     res.push_back({nums[i],nums[j],nums[k]});
                     
                     int first=nums[j],second=nums[k];
                     
                     while(j<k && nums[j]==first) j++;
                     while(j<k && nums[k]==second) k--;
                }
                 
              }
           
            while(i<n-2 && nums[i]==nums[i+1]) i++;
            
        }
        return res;
        
    }
};