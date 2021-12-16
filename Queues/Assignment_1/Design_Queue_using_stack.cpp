class MyQueue {
    stack<int>main,aux;
    int front;
public:
    MyQueue() {
     }
    
    void push(int x) {
        if(main.empty()) front=x;
         main.push(x);
        
    }
    
    int pop() {
        
        while(!main.empty())
        {   int x=main.top();
            aux.push(x);
            main.pop();
        }
        int ans=aux.top();
        aux.pop();
        if(!aux.empty()) front=aux.top();
        while(!aux.empty())
        {   int x=aux.top();
            main.push(x);
            aux.pop();
        }
        return ans;
     }
    
    int peek() {
        return front;
        
    }
    
    bool empty() {
        return main.empty();
        
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