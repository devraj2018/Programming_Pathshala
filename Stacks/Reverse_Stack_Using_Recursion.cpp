void insert_At_Bottom(stack<int>& s,int x)
{
    if(s.empty())
    {   s.push(x);
        return;
    }
    int y=s.top();
    s.pop();
    insert_At_Bottom(s,x);
    s.push(y);
}


void reverseStack(stack<int> &s) {
    if(s.empty()) return;
    int x=s.top();
    s.pop();
    reverseStack(s);
    insert_At_Bottom(s,x);
}