#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    
    public:
    stack<int>main,aux;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        main.push(val);
    }

    int deQueue() {
       if(!aux.empty()){
           int ans=aux.top();
           aux.pop();
           return ans;
       }
       if(main.empty()) return -1;
       
       while(!main.empty()) 
       {
           aux.push(main.top());
           main.pop();
       }
        
       
        int ans=aux.top();
           aux.pop();
           return ans;
       
    }

    int peek() {
       if(!aux.empty()) return aux.top();
        if(main.empty()) return -1;
       
       while(!main.empty()) 
       {
           aux.push(main.top());
           main.pop();
       }
        return aux.top();
        
    }

    bool isEmpty() {
        return (aux.empty() && main.empty());
    }
};