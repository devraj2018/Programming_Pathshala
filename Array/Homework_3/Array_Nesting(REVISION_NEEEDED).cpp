class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {  
              if(nums[i]>=0)
               { int cycle_length=1;
                 int index=nums[i];
                 int val=i;
              
                while(index!=i)
                   {
                    int temp=nums[index];
                    nums[index]=-(val+1);
                    val=index;
                    index=temp;
                    cycle_length++;
                  }
               nums[index]= -(val+1);
               ans=max(ans,cycle_length);   
              }
        }
        return ans;
        
    }
};