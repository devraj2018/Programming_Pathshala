class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++)
        {
            int j=i+1,k=n-1;
            
            while(j<k)
            {
                int sum= nums[i]+nums[j]+nums[k];
                
                if(sum==target)
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(sum>target) k--;
                else j++;
                
            }
            
            while(i<n-2 && nums[i]==nums[i+1]) i++;
            
        }
        return res;
    }
};