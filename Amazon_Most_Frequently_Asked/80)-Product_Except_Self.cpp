class Solution {   
public:
    // ===============          O(n) and Constant Space  ================// 
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int zero_count=0;
        int product=1;
        
        for(int i=0;i<nums.size();i++)
           {
              if(nums[i]==0) zero_count++;
              else product*=nums[i];
           }
        
        for(int i=0;i<nums.size();i++)
          {
             if(zero_count>1) nums[i]=0;
             else if(zero_count==1 && nums[i]==0) nums[i]=product;
             else if(zero_count==1 && nums[i]!=0) nums[i]=0;
             else nums[i]=product/nums[i];
          }
        return nums;
        
        
    }
};

==================================================================================================================
==================================================================================================================
==================================================================================================================


class Solution {
public:
 // ===============          O(n)Time and O(n) Space  ================// 
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>left(n,1),right(n,1),res(n);
        
        for(int i=1;i<n;i++)
        {   left[i]= left[i-1]*nums[i-1];
            right[n-i-1]=right[n-i]*nums[n-i];
        }
        
        
        for(int i=0;i<n;i++) res[i]=left[i]*right[i];
        return res;
    }
};
*/