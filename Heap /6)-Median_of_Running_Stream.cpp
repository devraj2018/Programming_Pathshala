class MedianFinder {
public:
    priority_queue<int>maxx;  // max_heap for the first half
    priority_queue<int,vector<int>,greater<int>>minn; // min_heap for the second half
    
    void addNum(int num) {
         if(maxx.empty() || maxx.top()>num) maxx.push(num);
         else minn.push(num);
        
        if(maxx.size()>(minn.size()+1)) // rebalance the two halfs to make sure the length difference is no larger than 1
            {   minn.push(maxx.top());
                maxx.pop(); 
            }
        else if(minn.size()>(maxx.size()+1))
            {   maxx.push(minn.top());
                minn.pop();
            }




      } 
    double findMedian() {
       if(maxx.size()==minn.size()) return (maxx.top()+minn.top())/2.0;
       return (maxx.size()>minn.size())?maxx.top():minn.top();
    }
};

