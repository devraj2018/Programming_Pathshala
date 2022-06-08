// Stack class.
class Stack {
    
public:
    int *arr;
    int capacity;
    int topp;
    Stack(int cap) {
       capacity=cap;
       arr=new int[cap];
        topp=-1;
     }

    void push(int num) {
       if(topp==capacity-1) return;
       arr[++topp]=num;
    }

    int pop() {
         if(topp==-1) return -1;
         int ans=arr[topp--];
         return ans;
    }
    
    int top() {
        if(topp==-1) return -1;
        return arr[topp];
    }
    
    int isEmpty() {
       return topp==-1;
    }
    
    int isFull() {
       return topp==capacity-1;
    }
    
};