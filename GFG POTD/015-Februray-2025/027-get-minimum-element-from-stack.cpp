// https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// ----------------- APPROACH - 1 : Using Two Stacks ------------------------------------------------------------------------------------------------
// TC : O(1) 
// SC : O(N) 
class Solution {
  public:
    stack<int> stk1;    // stores all the elements
    stack<int> stk2;    // stores the min elements 
    Solution() {}

    // Add an element to the top of Stack
    void push(int x) {
        if (stk1.empty()) {
            stk1.push(x);
            stk2.push(x);
        } else {
            if (x < stk2.top()) {
                stk2.push(x);
            } else {
                stk2.push(stk2.top());
            }
            stk1.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (!stk1.empty()) {
            stk1.pop();
            stk2.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        return stk1.empty() ? -1 : stk1.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        return stk2.empty() ? -1 : stk2.top();
    }
};

// ----------------- APPROACH - 2 : Using One Stacks of pair<int, int> ------------------------------------------------------------------------------------------------
// TC : O(1)
// SC : O(N)
class Solution {
    public:
    stack<pair<int, int>> stk;  // {element, min_element}
    Solution() {}

    // Add an element to the top of Stack
    void push(int x) {
        if (stk.empty()) {
            stk.push({x, x});
        } else {
            stk.push({x, min(x, stk.top().second)});
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (!stk.empty()) {
            stk.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        return stk.empty() ? -1 : stk.top().first;
    }

    // Finds minimum element of Stack
    int getMin() {
        return stk.empty() ? -1 : stk.top().second;
    }
};

// ----------------- APPROACH - 3 : Using One Stack and One Variable ------------------------------------------------------------------------------------------------
// TC : O(1)
// SC : O(N)
class Solution {
    public:
    stack<int> stk;
    int minEle;
    Solution() {
        minEle = -1;
    }

    // Add an element to the top of Stack
    void push(int x) {
        if (stk.empty()) {
            minEle = x;
            stk.push(x);
        } else {
            if (x < minEle) {
                int val = 2*x - minEle;
                stk.push(val);
                minEle = x;
            } else {
                stk.push(x);
            }
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (stk.empty()) {
            return;
        } 
        if (stk.top() < minEle) {
            minEle = 2*minEle - stk.top();
        }
        stk.pop();
    }

    // Returns top element of the Stack
    int peek() {
        if (stk.empty()) 
            return -1;
        return stk.top() < minEle ? minEle : stk.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        if (stk.empty())
            return -1;
        return minEle;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends