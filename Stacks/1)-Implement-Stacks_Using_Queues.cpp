class MyStack {
public:
     queue<int>q;
    int topp ;
    
    MyStack() {
       topp=-1; 
     }
    
    void push(int x) {
        
        q.push(x);
        topp=x;  
     }
    
    int pop() {
        
        if(q.empty()) {topp=-1; return -1;}
        
        queue<int>temp;
        
        while(q.size()!=1)
           {
            int x=q.front();
            temp.push(x);
            q.pop();
            
            if(q.size()==1) topp=x;
         
        }
        int x=q.front();
        q.pop();

        
        q=temp;
        return x;
        
        
    }
    
    int top() {
       return topp; 
        
    }
    
    bool empty() {
        if(q.empty()) return true;
        return false;
        
    }
};
