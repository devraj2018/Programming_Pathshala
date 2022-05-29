int Solution::braces(string A) {

    stack<char>s;
    for(int i=0;i<A.length();i++)
    {
           if(A[i]!=')') s.push(A[i]);
           else
           {
                int count=0;
                while(!s.empty() && s.top()!='(')
                {
                    count++;
                    s.pop();
                }
                if(count<=1) return 1;

                s.pop();
 
           }
          
    
    }
    return 0;
}
