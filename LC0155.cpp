class MinStack {
public:
    vector<vector<int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.size() == 0){
            st.push_back({val, val});
        }else{
            st.push_back({val, min(val, st.back()[1])});
        }
        return;
    }
    
    void pop() {
        st.pop_back();
        return;
    }
    
    int top() {
        return st.back()[0];
    }
    
    int getMin() {
        return st.back()[1];
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
