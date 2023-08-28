// https://leetcode.com/problems/implement-stack-using-queues/


#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;
    public:
        MyStack() {

        }

        void push(int x) {
            q.push(x);
            for(int i = 0; i < q.size()-1; i++) {
                int el = q.front();
                q.pop();
                q.push(el);
            }
        }

        int pop() {
            if(q.empty()) {
                return -1;
            } else {
                int el = q.front();
                q.pop();
                return el;
            }
        }

        int top() {
            if(q.size()) {
                return q.front();
            } else {
                return -1;
            }
        }

        bool empty() {
            if(q.size()) {
                return 0;
            } else {
                return 1;
            }
        }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */