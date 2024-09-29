// https://leetcode.com/problems/design-circular-deque/



#include <bits/stdc++.h>
using namespace std;

// --------------------------------------- USING LIST Library ----------------------------------------------------------------

class MyCircularDeque {
public:
    list<int> li;
    int k;
    MyCircularDeque(int k) : k(k) {}
    
    bool insertFront(int value) {
        if (li.size() < k) {
            li.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if (li.size() < k) {
            li.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if (!li.empty()) {
            li.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if (!li.empty()) {
            li.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if (!li.empty()) {
            return li.front();
        }
        return -1;
    }
    
    int getRear() {
        if (!li.empty()) {
            return li.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        return li.empty();
    }
    
    bool isFull() {
        return li.size() == k;
    }
};



// ------------------------------------- USING ARRAY ---------------------------------------------------------------------------

class MyCircularDeque {
public:
    int *arr;
    int front;
    int rear;
    int k;
    int count;
    MyCircularDeque(int k) {
        this -> k = k;
        arr = new int[k];
        front = 0;
        rear  = k - 1;
        count = 0;
    }

    ~MyCircularDeque() {
        delete[] arr; // Clean up allocated memory
    }
    
    bool insertFront(int value) {
        if (count < k) {
            front = (front - 1 + k) % k;
            arr[front] = value;
            count ++;
            return true;
        }
        return false;   // isFull() == 1
    }
    
    bool insertLast(int value) {
        if (count < k) {
            rear = (rear + 1) % k;
            arr[rear] = value;
            count ++;
            return true;
        }
        return false;   // isFull() == 1
    }
    
    bool deleteFront() {
        if (count) {
            front = (front + 1) % k;
            count --;
            return true;
        }
        return false; // isEmpty() == 1
    }
    
    bool deleteLast() {
        if (count) {
            rear = (rear - 1 + k) % k;
            count --;
            return true;
        }
        return false; // isEmpty() == 1
    }
    
    int getFront() {
        if (count) {
            return arr[front];
        }
        return -1;  // isEmpty() == 1
    }
    
    int getRear() {
        if (count) {
            return arr[rear];
        }
        return -1;  // isEmpty() == 1
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */