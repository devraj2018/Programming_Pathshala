// ---------------------Swaping method-----------------------//
class Solution {  
public:
    vector<vector<int>>res;
     void helper(vector<int>&nums,int curr_I=0)
      {  if(curr_I==nums.size())
            {
             res.push_back(nums);
             return;
            }
         
         for(int i=curr_I;i<nums.size();i++)
           {
            swap(nums[curr_I],nums[i]);
            helper(nums,curr_I+1);
            swap(nums[curr_I],nums[i]);
           }
     }
    
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums);
        return res;
        
    }
};

// -------------------  By Traversing for all and not taking which is already the part of curr string--------------//
class Solution {
public:
    vector<vector<int>>res;
    vector<int>temp;
    unordered_set<int>s;
    void helper(vector<int>&nums,int curr_I)
    {
         if(curr_I==nums.size()) return;
         
         for(int i=0;i<nums.size();i++)
             {
              if(s.find(nums[i])!=s.end()) continue;   // Skipping part
               
              temp.push_back(nums[i]);
              s.insert(nums[i]);
              if(temp.size()==nums.size())
                {
                  res.push_back(temp);
                }
              helper(nums,curr_I+1);
              
              s.erase(nums[i]);   // Backtracking
              temp.pop_back();    // Backtracking
         }
        
     }
    vector<vector<int>> permute(vector<int>& nums) {
     
        int curr_I=0;
        helper(nums,curr_I);
        return res;
        
     }
};
