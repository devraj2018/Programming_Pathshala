//. O(1) push and Amotized O(1) pop

class MyQueue {
public:
    stack<int>push_stack,pop_stack;
    MyQueue() {
     }
     void push(int x) {
         push_stack.push(x);
      }
     int pop() {
        int ans=-1;
        if(!pop_stack.empty())
        {    ans=pop_stack.top();
             pop_stack.pop();
             return ans;
        }
        if(push_stack.empty())  return ans;
        
        while(!push_stack.empty())
        {    pop_stack.push(push_stack.top());
             push_stack.pop();
        }
        ans=pop_stack.top();
        pop_stack.pop();
        return ans;
     }
    
    int peek() {
        if(empty()) return -1;
        if(!pop_stack.empty()) return pop_stack.top();
        
        while(!push_stack.empty())
        {    pop_stack.push(push_stack.top());
             push_stack.pop();
        }
        if(!pop_stack.empty()) return pop_stack.top();
        return -1;
            
        
        
    }
    
    bool empty() {
        if(push_stack.empty()==true && pop_stack.empty()==true) return true;
        return false;
        
    }
};

//--------------               Pop takes O(n)time and psuh takes 0(1)time             ------------------//

/* class MyQueue {     
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
    
    int peek() { return front;
      }
    
    bool empty() {  return main.empty();
     }
};
*/

/* Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */