class MinStack {
private:
        std::stack<int> mainStack;
        std::stack<int> minStack;
public:
    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        if ( minStack.empty() || val < minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }
    
    int top() {
        if (!mainStack.empty()) return mainStack.top();
        throw runtime_error("Stack is empty");
    }
    
    int getMin() {
        return minStack.top();
        throw runtime_error("Stack is empty");
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */