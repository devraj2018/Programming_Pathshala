vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
  
  
    queue<long long int>q;
    vector<long long>res;
    for(long long int i=0;i<K;i++)
      {
        if(A[i]<0) q.push(i);
      }
    
      if(q.empty()) res.push_back(0);
      else res.push_back(A[q.front()]);
     for(long long i=K;i<N;i++)
        {
         if(A[i]<0) q.push(i);
         if(!q.empty() && i-q.front()>=K) q.pop();
        
         if(q.empty()) res.push_back(0);
         else
         res.push_back(A[q.front()]);
    }
    return res;
                                                 
 }