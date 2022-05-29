class CustomStack {    // If this will implemented using vector this will easy and more efficient
public:
    int curr_size=0,capacity;
    stack<int>s,aux;
    CustomStack(int maxSize) {
      capacity=maxSize;  
    }
    
    void push(int x) {
        
        if(curr_size>=capacity) return;
        curr_size++;
        s.push(x);
        
    }
    
    int pop() {
        if(curr_size==0) return -1;
        int ans=s.top();s.pop();
        curr_size--;
        return ans;
        
    }
    
    
    void increment(int k, int val) {
        
        int loop= k>curr_size ? 0:curr_size-k;
         for(int i=1;i<=loop;i++)
        {   aux.push(s.top());
             s.pop();
        }
        while(!s.empty())
        {
           aux.push(s.top()+val);
             s.pop();  
        }
         while(!aux.empty())
        {
           s.push(aux.top() );
             aux.pop();  
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */