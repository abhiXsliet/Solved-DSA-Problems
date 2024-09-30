// https://leetcode.com/problems/design-a-stack-with-increment-operation/




#include <bits/stdc++.h>
using namespace std;

// ------------------------------------- BRUTE (Fixed sized ARRAY) ----------------------------------------------------------------
// While Popping the size of array should be reducing which is not happening here.

/* 
 Time Complexity: O(T * N)
 - T: Total number of operations performed on the CustomStack (push, pop, increment)
 - N: In the worst case, the increment function processes up to 'N' elements per call, 
      where 'N' is the maximum size of the stack.

 Space Complexity: O(N)
 - N: Represents the maximum size of the array used to store elements in the stack.
 */
class CustomStack {
public:
    int *arr;
    int top;
    int size;

    // CustomStack(int maxSize) : top(-1), size(maxSize), arr(new int[maxSize]) {}

    CustomStack(int maxSize) {
        top  = -1;
        size = maxSize;
        arr  = new int[maxSize];
    }
        
    void push(int x) {
        if (top + 1 < size) {
            top ++;
            arr[top] = x;
        }
    }
    
    int pop() {
        if (top >= 0) {
            return arr[top --];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int i = 0;
        while (i < min(k, size)) {
            arr[i] += val;
            i ++;
        }
    }
};


// -------------------------------------- BETTER (VECTOR) --------------------------------------------------------------
// The vector version is better due to its dynamic nature (since actual number of elements stored is much smaller than the maxSize), 
// though it may incur occasional resizing costs.

/* 
 Time Complexity: O(T * N)
 - T: Total number of operations performed on the CustomStack (push, pop, increment)
 - N: In the worst case, the increment function processes up to 'N' elements per call, 
      where 'N' is the maximum size of the stack.

 Space Complexity: O(N)
 - N: Represents the maximum size of the array used to store elements in the stack.
 */
class CustomStack {
public:
    vector<int> stk;
    int top;
    int stkSize;

    CustomStack(int maxSize) : top(-1), stkSize(maxSize) {}
    
    void push(int x) {
        if ((top + 1) < stkSize) {
            top ++;
            stk.push_back(x);
        }
    }
    
    int pop() {
        if (top >= 0) {
            int val = stk[top --];
            stk.pop_back();
            return  val;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, (top + 1)); i ++) {
            stk[i] += val;
        }
    }
};

// ----------------------------------------- OPTIMAL -------------------------------------------------------------------

class CustomStack {
public:
    int top;
    int n;
    vector<int> stk;
    vector<int> inc;    // keeps the track of indices till (i) to increment by stored value

    CustomStack(int maxSize) : top(-1), n(maxSize) {}
    
    void push(int x) {
        if ((top + 1) < n) {
            top ++;
            stk.push_back(x);
            inc.push_back(0);   // no increment till now
        }
    }
    
    int pop() {
        if (top >= 0) {
            if (top > 0) {  // LAZY PROPAGATION
                inc[top - 1] += inc[top];
            }

            int incV = inc[top];
            int val  = stk[top];
            top --;

            stk.pop_back();
            inc.pop_back();

            return val + incV;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int idx  = min(k - 1, top);
        if (idx >= 0) {
            inc[idx] += val; 
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */