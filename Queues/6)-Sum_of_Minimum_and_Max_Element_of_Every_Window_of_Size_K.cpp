//. If array is Sorted Then first ele of every window is minimum
//. If array is Sorted Then last ele of every window is maximum

// brute force  0( (n-k)*k) )  almost 0( n* k)

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
    
    deque<int>maxx,minn;
    
    for(int i=0;i<k;i++)
       {
          while(!maxx.empty() && nums[maxx.back()]< nums[i])
               maxx.pop_back();
        
          while(!minn.empty() && nums[minn.back()]> nums[i])
            minn.pop_back();
        
         maxx.push_back(i);
          minn.push_back(i);
       }
       
    
      long long ans=0;
      ans+= nums[maxx.front()] + nums[minn.front()];
    
       for(int i=k;i<n;i++)
            {
        
                while(!maxx.empty() && nums[maxx.back()]< nums[i])  //For Monotonicity
                    maxx.pop_back();
        
                while(!minn.empty() && nums[minn.back()]> nums[i])  //For Monotonicity
                    minn.pop_back();
        
                while(!maxx.empty() &&  maxx.front()<= (i-k))      //For removing out of window ele
                    maxx.pop_front(); 
        
                 while(!minn.empty() &&  minn.front()<= (i-k))    //For removing out of window ele
                    minn.pop_front();
        
                 maxx.push_back(i);
                 minn.push_back(i);
        
                  ans+= nums[maxx.front()] + nums[minn.front()];
            }
       return ans;
	
}
