class MinStack {
public:
    stack<int>s,minn;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty() || val<=minn.top())
            minn.push(val);
         s.push(val);
        
    }
    
    void pop() {
       
         if(s.top()==minn.top())
            minn.pop();
        s.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minn.top();
    }
};
