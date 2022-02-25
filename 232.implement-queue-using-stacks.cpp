/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
    stack<int> st1, st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int x;
        if(st2.empty()){
            while(!st1.empty()){
                x = st1.top();
                st1.pop();
                st2.push(x);
            }
        }
        x = st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {
        int x;
        if(st2.empty()){
            while(!st1.empty()){
                x = st1.top();
                st1.pop();
                st2.push(x);
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

