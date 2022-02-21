/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
//#include<queue>
class MyStack {
    queue<int> q1;
    queue<int> q2;
    queue<int> *fq = &q1;
    queue<int> *eq = &q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        fq->push(x);
        //cout<<fq.size();
    }
    
    int pop() {
        int r = fq->back();
        int n = fq->size();
        for(int i = 0; i < n - 1; i++){
            int t = fq->front();
            fq->pop();
            eq->push(t);
        }
        fq->pop();
        queue<int> *tempq = fq;
        fq = eq;
        eq = tempq;
        //cout<<fq->size();
        //cout<<eq->size();
        return r;
    }
    
    int top() {
        return fq->back();
    }
    
    bool empty() {
        //cout<<fq->size();
        return fq->empty();
    }
};
//["MyStack","push","push","top","pop","pop","empty"]\n[[],[1],[2],[],[],[],[]]
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

