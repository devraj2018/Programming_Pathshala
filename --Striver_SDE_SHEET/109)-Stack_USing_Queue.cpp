#include<bits/stdc++.h>
class Stack {
	// Define the data members.

   public:
    deque<int>main;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return main.size();
    }

    bool isEmpty() {
       return main.empty();
    }

    void push(int element) {
        main.push_back(element);
    }

    int pop() {
        
        if(main.empty()) return -1;
        int ans=main.back();
        main.pop_back();
        return ans;
       
    }

    int top() {
         if(main.empty()) return -1;
        return main.back();
    }
};