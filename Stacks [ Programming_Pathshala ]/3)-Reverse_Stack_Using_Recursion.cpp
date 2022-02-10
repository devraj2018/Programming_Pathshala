void  insert_at_bottom(int x,stack<int> &stack)
   {
     if(stack.empty())
       {
         stack.push(x);
         return;
       }
    
      int a=stack.top();
      stack.pop();
      insert_at_bottom(x,stack);
    
      stack.push(a);
    }
void reverseStack(stack<int> &stack) {
   
    if(stack.empty()) return;
    
    int x= stack.top();
    stack.pop();
    reverseStack(stack);
    
   insert_at_bottom(x,stack);
    
    
    
     
    
}