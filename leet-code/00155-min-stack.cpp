class MinStack {
public:
    std::stack<int> s;
    std::stack<int> min;

    MinStack() {
    }
    
    void push(int x) {
        // always push on s
        s.push(x);
        // check if we have a new min
        if (min.empty() || x <= min.top()) {
            min.push(x);
        }
    }
    
    void pop() {
        if (s.top() == min.top()) {
            min.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */