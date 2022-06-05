class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majele=0;
        int majcount=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==majele)
            {
                majcount++;
                
            }
            else if(majcount==0)
            {
                majcount=1;
                majele=nums[i];
            }
            else
                majcount--;
        }
        
        return majele;
        
    }
};