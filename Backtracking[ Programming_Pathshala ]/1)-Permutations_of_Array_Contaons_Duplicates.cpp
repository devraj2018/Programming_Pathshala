class Solution {
public:
    unordered_map<int,int>freq;
    vector<vector<int>>ans;
    vector<int> temp;
    void helper(vector<int>&nums,int curr_I=0)
    { 
         if(curr_I==nums.size())
         {
             ans.push_back(temp);
             return;
         }
        
        for(int i=0;i<nums.size();i++)
        {     
             if(i+1<nums.size() && nums[i]==nums[i+1])
                 continue;
             
              if(freq[nums[i]]==0)
                  continue;
              
              temp.push_back(nums[i]);
              freq[nums[i]]--;
              helper(nums,curr_I+1);
              freq[nums[i]]++;
              temp.pop_back();
            
         }
        
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       
        for(auto x:nums) freq[x]++;
        
        sort(nums.begin(),nums.end());
        helper(nums);
        return ans;
    }
};