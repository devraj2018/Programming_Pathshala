vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    vector<long long>res;
    long long int i;
    
    queue< long long int>q;   //only store index of negative ele
    
    for(i=0;i<K;i++)
         {
            if(A[i]<0)  q.push(i);
         }
    
     if(q.empty()) res.push_back(0);
     else res.push_back(A[q.front()]);
    
     for(i=K;i<N;i++)
          {
            while(!q.empty() && q.front()<= (i-K)) q.pop();  // Remove element from out of window range
              
            if(A[i]<0)  q.push(i);  // Push curr ele bcz this may also be answer

            if(q.empty()) res.push_back(0);
            else res.push_back(A[q.front()]);
        
          }
      return res;
 }