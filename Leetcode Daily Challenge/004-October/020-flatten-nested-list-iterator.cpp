// https://leetcode.com/problems/flatten-nested-list-iterator/


#include <bits/stdc++.h>
using namespace std;


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


/* 
 Approach 1: Using Stack with Object Copies
 */
class NestedIterator {
public:
    // Stack with object copies
    stack<NestedInteger> st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        
        for (int i = n - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        int num = st.top().getInteger();
        st.pop();
        return num;
    }
    // TC = O(N)
    bool hasNext() {
        if (st.empty()) 
            return false;

        while(!st.empty()) {
            NestedInteger curr = st.top();

            if (curr.isInteger()) 
                return true;

            st.pop();

            vector<NestedInteger> list = curr.getList();

            for (int i = list.size() - 1; i >= 0; i--) {
                st.push(list[i]);
            }
        }

        return false;
    }
};


/**
 Approach 2: Using Stack with Addresses to Avoid Object Copies
 */

class NestedIterator {
public:
    // Stack with addresses
    stack<NestedInteger*> st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        
        for (int i = n - 1; i >= 0; i--) {
            st.push(&nestedList[i]);
        }
    }
    // TC = O(1)
    int next() {
        int num = st.top()->getInteger();
        st.pop();
        return num;
    }
    // TC = O(N)
    bool hasNext() {
        if (st.empty()) 
            return false;

        while(!st.empty()) {
            NestedInteger* curr = st.top();

            if (curr->isInteger()) 
                return true;

            st.pop();

            vector<NestedInteger> &list = curr->getList();

            for (int i = list.size() - 1; i >= 0; i--) {
                st.push(&list[i]);
            }
        }

        return false;
    }
};



/**
 Approach - 3 : Using Queue 
 Time Complexity of hasnext() and next() functions are optimized to O(1) 
 since it is being called for again and again
 */

class NestedIterator {
public:
    // Queue for optimization
    queue<int> que;
    
    void Flatten(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for (int i = 0; i < n; i++) {
            NestedInteger& obj = nestedList[i];

            if (obj.isInteger()) {
                que.push(obj.getInteger());
            }
            else {
                Flatten(obj.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        Flatten(nestedList);
    }

    // TC = O(1)
    int next() {
        int num = que.front();
        que.pop();
        return num;
    }

    // TC = O(1)
    bool hasNext() {
        return !que.empty();
    }
};