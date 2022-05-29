class MinStack {
public:
    stack<int>s,minn;
    MinStack() {
      }
    
    void push(int val) {
       if(minn.empty() || minn.top()>=val)  minn.push(val);
        s.push(val);
     }
    
    void pop() {
        if(s.top()==minn.top())  minn.pop();
        s.pop();

        
     }
    
    int top() {
        return s.top();
     }
    
    int getMin() {
        return minn.top();
     }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */