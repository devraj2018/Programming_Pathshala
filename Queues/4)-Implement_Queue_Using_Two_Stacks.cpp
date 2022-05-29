class MyQueue {
    Stack<Integer> main;
    Stack<Integer> show;
    /** Initialize your data structure here. */
    public MyQueue() {
        main=new Stack<>();
        show=new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        main.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (show.isEmpty()) {
            while (!main.isEmpty()) {
                show.push(main.pop());
            }
        }
        return show.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if (show.isEmpty()) {
            while (!main.isEmpty()) {
                show.push(main.pop());
            }
        }
        return show.peek();
    }
    
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return main.isEmpty() && show.isEmpty();
    }
}