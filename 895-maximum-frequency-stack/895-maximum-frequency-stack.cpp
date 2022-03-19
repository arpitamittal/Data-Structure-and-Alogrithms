class FreqStack {
public:
    //Current maximum element
    int currMax = 0;
    // Element -> frequency
    unordered_map<int, int> freq;
    // Frequency -> Stack in which the elements reached by order
    unordered_map<int, stack<int>> store;
    FreqStack() {
        
    }
    
    void push(int val) {
        //Store frequencies in the map
        freq[val]++;
        // Find the maximum element
        currMax = max(currMax, freq[val]);
        // Stores in the stack that this element has reached it's maximum
        store[freq[val]].push(val);
        
    }
    
    int pop() {
        // Find element with maximum frequency
        int answer = store[currMax].top();
        // Pop element of maximum frequency
        store[currMax].pop();
        // If the popped element empty the stack then decrease it
        
        if(store[freq[answer]--].empty())
            currMax--;
        
        return answer;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */