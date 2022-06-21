
================================================================================================
================================  Using Two Pointer O(n)Time and O(1)space ==================
=======================================================================================
int longestSubSeg(vector<int> &arr , int n, int k) 
{ 

	// Stores count of zero in the array under consideration.
    int cnt0 = 0;
    int l = 0; 
    int maxLen = 0; 
  
    // r decides current ending point, i.e. the right pointer.
    for (int r = 0; r < n; r++) { 
        if (arr[r] == 0) {
            cnt0++; 
        }
  
        // If there are more 0's move left pointer towards current ending point. 
        while (cnt0 > k) { 
            if (arr[l] == 0) {
                cnt0--; 
            }

            l++; 
        } 
  
        maxLen = max(maxLen, r - l + 1); 
    }
	
    return maxLen; 
} 


================================================================================================
================================  Using Queue O(n)Time and O(n)space ==================
=======================================================================================

int longestSubSeg(vector<int> &arr , int n, int k) 
{ 

    // Starting index of array under consideration.
    int l = 0;
    int max_len = 0; 
    queue<int>q;
    // To store current size of the queue. 
    int size = 0;
  
    // i decides current ending point, i.e. the right pointer.	
    for (int r = 0; r < n; r++) { 
        if (arr[r] == 0){
            q.push(r);
            size++;
        } 
        
        // Updating queue when its size becomes greater than k.        
        if (size > k) { 
            // Updating starting index of array under consideration.
            l = q.front() + 1;
            q.pop();
            size--;
        } 
  
        max_len = max(max_len, r - l + 1); 
    }

    return max_len; 
} 


================================================================================================
================================  Brute Force O(n^2) ================================
================================================================================================
int longestSubSeg(vector<int> &arr , int n, int k) 
{ 
    int maxLen = 0; 
    int i,j;
    for(i = 0; i < n; i++){
    	int kCopy = k;  	
        if(arr[i] == 0){
    		 if(kCopy > 0) kCopy--;
		     else continue;
		  	}

		 
    	for(j = i+1; j<n; j++){
    		if(arr[j] == 0){
	    		if(kCopy > 0){
	    			kCopy--;
				}
				else{
					break;
				}
			}	
		}
	  maxLen = max(maxLen , j-i);	
	}
  
    return maxLen; 
} 
