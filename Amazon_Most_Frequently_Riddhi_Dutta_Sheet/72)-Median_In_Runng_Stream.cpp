class MedianFinder {
public:
    priority_queue<int>maxx;
    priority_queue<int,vector<int>,greater<int>>minn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxx.empty() ||num<= maxx.top())
            maxx.push(num);
        else
            minn.push(num);
        
        if(maxx.size()>1+minn.size())
        {
            minn.push(maxx.top());
            maxx.pop();
        }
        if(minn.size()>1+maxx.size())
        {
            maxx.push(minn.top());
            minn.pop();
        }
    }
    
    double findMedian() {
        
        if(maxx.size()==minn.size()) return (maxx.top()+minn.top())/2.0;
        
        return maxx.size()>minn.size()?maxx.top()/1.0:minn.top()/1.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */