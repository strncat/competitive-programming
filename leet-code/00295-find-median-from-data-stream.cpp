class MedianFinder {
public:
    // key idea: keep the largest elements in the min heap and the smallest elements 
    // in the max heap. This way, at any point of time, the median can be returned in O(1)
    // time because the middle value or two values are at min_heap.top() and max_heap.top()
    priority_queue<int> max_heap;
    priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    MedianFinder() {}
    
    void addNum(int num) {
        // base case
        if (min_heap.empty()) { min_heap.push(num); return; }
        
        // otherwise, normal case
        if (num > min_heap.top()) { // min holds the largest elements
            min_heap.push(num);
        } else {
            max_heap.push(num);
        }

        // rebalance
        if (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
            
        } else if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if (min_heap.empty() && max_heap.empty()) { return 0; }
        if (min_heap.empty()) { return max_heap.top(); }
        if (max_heap.empty()) { return min_heap.top(); }
        
        if (min_heap.size() == max_heap.size()) {
            return (min_heap.top() + max_heap.top()) / 2.0;
        } else {
            return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */