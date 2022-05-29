vector<int> Solution::repeatedNumber(const vector<int> &A) {

  int xorr=0;
  for(int i=0;i<A.size();i++)
  {
      xorr^=A[i];
      xorr^=(i+1);
  }

  int rightset= xorr & ~(xorr-1);

  int x=0,y=0;
   
    for(int i=0;i<A.size();i++)
    {
             if(rightset&A[i]) x^=A[i];
             else
               y^=A[i];

             if((i+1)&rightset) x^=(i+1);
             else y^=(i+1);  
 
    }
    int countx=0;
    for(int i=0;i<A.size();i++)
    { if(x==A[i]) countx++;

    }
    vector<int>res;

    if(countx==0) return {y,x};
    return {x,y};

}