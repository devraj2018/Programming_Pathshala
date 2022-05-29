int Solution::braces(string A) {
    int n=A.length();
    int i=0;
    stack<char>stk;

    while(i<n)
    {
              if(A[i]!=')')
                  {
                    stk.push(A[i]);
                    i++;
                  }
              else
                  {

                      
                     int count=0;
                     while(!stk.empty() && stk.top()!='(')
                         {
                              stk.pop();
                              count++;
                         }
                      if(count<2) return true;

                      stk.pop();
                      i++;
                  }
     }
    return false;
}
