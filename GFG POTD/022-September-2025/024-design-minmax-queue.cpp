// https://www.geeksforgeeks.org/problems/design-minmax-queue/1/




#include <bits/stdc++.h>
using namespace std;

class SpecialQueue {
  private:
    queue<int> q;
    deque<int> minQ, maxQ;
  public:

    void enqueue(int x) {
        q.push(x);
        
        // Maintain MinQ Increasing
        while (!minQ.empty() && minQ.back() > x) minQ.pop_back();
        minQ.push_back(x);
        
        // Maintain MaxQ Decreasing
        while (!maxQ.empty() && maxQ.back() < x) maxQ.pop_back();
        maxQ.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return;
        int front = q.front();
        q.pop();
        
        // if the front is at the minQ or at maxQ pop it
        if (!minQ.empty() && front == minQ.front()) minQ.pop_front();
        if (!maxQ.empty() && front == maxQ.front()) maxQ.pop_front();

    }

    int getFront() {
        if (!q.empty()) return q.front();
        return -1;
    }

    int getMin() {
        if (!minQ.empty()) return minQ.front();
        return -1;
    }

    int getMax() {
        if (!maxQ.empty()) return maxQ.front();
        return -1;
    }
};