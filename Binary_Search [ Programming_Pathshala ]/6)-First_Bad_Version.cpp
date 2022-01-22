// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
             int low=1,high=n;
             int ans=-1,mid;
			  while(low<=high)
			     {   mid= high -(high-low)/2;
                     bool version=isBadVersion(mid);
					 if(version)
						 {   
                              if(mid==1) 
                                  return 1;
                              bool prev=isBadVersion(mid-1);
                              if(prev)
                              {
                                  ans=mid;
                                  high=mid-1;
                              }
                              else
                              {
                                  return mid;
                              }
                            
					       }
					  else {
                          low=mid+1;
                      }
			    }
        return 0;
        
    }
};