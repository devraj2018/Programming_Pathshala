class MyQueue {
public:
    stack<int>s1,s2;
    int peek_ele=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
            s1.push(x);
         }
    
    int pop() {
        
        if(s1.empty() && s2.empty()) return -1;
        
        int ans=-1;
        if(!s2.empty()) 
        {
            ans=s2.top();
            s2.pop();
            return ans;
        }
        
         
        
        while(!s1.empty())
        {
             int x=s1.top();
            s1.pop();
            s2.push(x);
            
        }
        ans=s2.top();
        s2.pop();
        return ans;
        
    }
    
    int peek() {
        
        if(!s2.empty()) return s2.top();
        if(s1.empty() && s2.empty()) return -1;
        
        while(!s1.empty())
        {
             int x=s1.top();
             s1.pop();
             s2.push(x);
            
        }
        int ans=s2.top();
        return ans;
        
    }
    
    bool empty() {
         if(s1.empty() && s2.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */