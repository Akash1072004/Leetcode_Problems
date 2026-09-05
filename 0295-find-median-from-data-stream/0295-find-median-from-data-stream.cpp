class MedianFinder {
public:
    priority_queue<double>pq;
    priority_queue<double,vector<double>,greater<double>>p;
    void addNum(int num) {
        if(pq.size() ==0 || num<=pq.top())pq.push(num);
        else p.push(num);
        if(pq.size()>p.size()+1){
            int temp = pq.top();
            pq.pop();
            p.push(temp);
        }
        else if(p.size()>pq.size()+1){
            int temp = p.top();
            p.pop();
            pq.push(temp);
         }
    }
    
    double findMedian() {
        if(pq.size()==p.size())return (pq.top()+p.top())/2.0;
        else {
            if(pq.size()>p.size())return pq.top();
            else return p.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */