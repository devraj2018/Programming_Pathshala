class Solution {
public:
 //----   Method 1-- We can use unordered_map to store frequency --O(n)time O(n)space---///

       // --------- Easily Doable, No need to write code of that ----------// 

 //---Method  2--- Boyer's Moore Algorithm  O(n)Time O(1)spcae ----//
    int majorityElement(vector<int>& nums) {
        int count=1;
        int maj_ele=nums[0];
        for(int i=1;i<nums.size();i++)
        {
             if(nums[i]==maj_ele)
             {
                 count++;
             }
            else
                count--;
            
            if(count==0)
            {
                maj_ele=nums[i];
                count=1;
            }
            
        }
        return maj_ele;
        
        
        
    }
};