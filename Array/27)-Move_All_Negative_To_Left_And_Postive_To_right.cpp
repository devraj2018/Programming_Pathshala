vector<int> separateNegativeAndPositive(vector<int> &nums){
   
    int i=0;
    int e=nums.size()-1;
    int j=0;
    
    while(j<=e)
    {
          if(nums[j]<0)
          {
              swap(nums[i],nums[j]);
              i++;j++;
          }
         else if(nums[j]>0)
         {
             swap(nums[j],nums[e]);
             e--;
         }
         else{
             j++;
         }
         
        
        
    }
    return nums;
    
}