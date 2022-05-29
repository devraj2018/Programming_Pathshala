class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string expp)
    {
        stack<int>s;
   
       int i=0;int n=expp.length();
       while(i<n)
          {
            if(expp[i]=='*')
               {
                 int a=s.top() ; s.pop();
                 int b=s.top() ; s.pop();
                 s.push(a*b);
               }
            else if(expp[i]=='/')
              {
                 int a=s.top() ; s.pop();
                 int b=s.top() ; s.pop();
                 s.push(b/a);
              }
             else if(expp[i]=='+')
               {
                   int a=s.top() ; s.pop();
                   int b=s.top() ; s.pop();
                   s.push(a+b);
               }
            else if(expp[i]=='-')
               {
                 int a=s.top() ; s.pop();
                 int b=s.top() ; s.pop();

                 
                 s.push(b-a);
               }
       
            else s.push(expp[i]-'0');
       
             i++;
       
           }
   return s.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends