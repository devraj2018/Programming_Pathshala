    vector<int> res; // Globally declared vector
    void helper(vector<int> arr,int N,int &curr_sum,int curr_I=0)
    {
        if(curr_I==N)
           {  res.push_back(curr_sum);
                 return;
           }
         
          helper(arr,N,curr_sum,curr_I+1); // Element not taken
         
          curr_sum+=arr[curr_I];
          helper(arr,N,curr_sum,curr_I+1); //Element taken
          curr_sum-=arr[curr_I];  // Backtracking step
              
             
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {   int curr_sum=0;
        helper(arr,N,curr_sum);
        return res;
        
    }