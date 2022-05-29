class Solution{
	
	
	public:
	bool areConsecutives(long long arr[], int n) 
	{ 
	    long long minn=LLONG_MAX,maxx=LLONG_MIN;
	    
	    for(int i=0;i<n;i++)
	    {
	         maxx=max(maxx,arr[i]);
	         minn=min(minn,arr[i]);
	         
	    }
	    
	    if(maxx-minn+1 != (long long)n) return false;
	    
	    int i=0;
	    int to_add= (-1)*minn;
	     
	    while(i<n)
	       {
	           if( arr[i] + to_add == i)
	             {
	               i++;
	               continue;
	            }
	           int temp=arr[i];
	           swap(arr[i],arr[arr[i]+to_add]);
	           
	           if(arr[i]==temp) return false;
	      }
		  
	    return true;
 	}
		 

};