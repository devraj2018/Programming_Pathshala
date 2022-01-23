class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candidates,vector<int>&curr,int &target,int curr_sum=0,int curr_I=0)
    {    if(curr_sum==target)
          {
              res.push_back(curr);return;
          }
          if(curr_sum>target) return;
        
          for(int i=curr_I;i<candidates.size();i++)
             {
               curr_sum+= candidates[i];
               curr.push_back(candidates[i]);
             
               helper(candidates,curr,target,curr_sum,i);
            
               curr_sum-= candidates[i];
               curr.pop_back();
             }     
    }
    void another_way_of_writing_this_code(vector<int>& candidates,vector<int>&curr,int &target,int curr_sum=0,int curr_I=0)
    {   if(curr_I== candidates.size())
          return; 
        if(curr_sum==target)
          {
              res.push_back(curr);return;
          }
          if(curr_sum>target) return;
        
           helper(candidates,curr,target,curr_sum,curr_I+1); // Don't take curr_element->Excluding curr Element

           curr_sum+= candidates[curr_I];
           curr.push_back(candidates[curr_I]);

           helper(candidates,curr,target,curr_sum,curr_I); //Use curr Element and call Recursively 
           curr_sum- = candidates[curr_I];                 //By including curr Element in next part too
           curr.pop_back();            //That's y ,I dont increment curr_I(This is curr Index)

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>curr;
       // Sorting of candidates not needed
       // If we have nagative element in array-->> We will get infinte subsets
       // So our array can only contain +ve Elements 
        helper(candidates,curr,target);
        return res;
        
        
    }
};