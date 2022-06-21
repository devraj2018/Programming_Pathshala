// Implement class for minStack.
#include<bits/stdc++.h>
class minStack
{
	 
	
	public:
		
		 stack<int>main,minn;
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if(minn.empty() || num<=minn.top())
                minn.push(num);
            main.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
		     if(main.empty()) return -1;
            
             if(main.top()==minn.top()) minn.pop();
            int ans=main.top();main.pop();
            return ans;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			 if(main.empty()) return -1;
             return main.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
		 if(main.empty()) return -1;
            return minn.top();
		}
};