/*
1 x  -Push the element x into the stack.
2    -Delete the element present at the top of the stack.
3    -Print the maximum element in the stack.

STDIN   Function
-----   --------
10      operations[] size n = 10
1 97    operations = ['1 97', '2', '1 20', ....]
2
1 20
2
1 26
1 20
2
3
1 91
3

*/

vector<int> getMax(vector<string> operations) {
    vector<int> res; 
    stack<int>s,maxx;
    
    for(int i=0;i<operations.size();i++)
    {    if(operations[i][0]=='1')
             { int n=operations[i].length();
               string temp= operations[i].substr(2);
               int val=stoi(temp);
               
               if(maxx.empty() || maxx.top()<=val)
               maxx.push(val);
               s.push(val);
              }
             else if(operations[i][0]=='3')
              {
                  if(maxx.empty()) res.push_back(-1);
                  else  res.push_back(maxx.top());
              }
           else {
                 if(maxx.top()==s.top()) maxx.pop();
                 s.pop();
               }
      
    }
    return res;
}