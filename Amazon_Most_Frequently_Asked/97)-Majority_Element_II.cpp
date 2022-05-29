class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>res;
        int majcount1=0,majcount2=0;
        int majele1,majele2;
        int n=nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
             
              
                if(majele1==nums[i])
                {
                   majcount1++;
                }
             else if(majele2==nums[i])
                 {  majcount2++;
                 }
            else if(majcount1==0)
                {   majele1=nums[i];
                    majcount1=1;
                }
               else if(majcount2==0)
                {  majele2=nums[i];
                   majcount2=1;
                }
              
               else 
                 {
                   majcount1--;
                   majcount2--;
                 }
            
        }
        majcount1=0,majcount2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==majele1) majcount1++;
            else if(nums[i]==majele2) majcount2++;
        }
        
     //   cout<<majele1<<" "<<majele2<<endl;
        
        if(majcount1>n/3) res.push_back(majele1);
        if(majcount2>n/3) res.push_back(majele2);
        return res;
    }
};