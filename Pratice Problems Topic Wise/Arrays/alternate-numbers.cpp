// https://www.codingninjas.com/studio/problems/alternate-numbers_6783445


#include <bits/stdc++.h>
using namespace std;

// TC = O(N)
// SC = O(N)
vector<int> solve_brute(vector<int>& arr, int n) {
    vector<int> neg;
    vector<int> pos;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            neg.push_back(arr[i]);
        }
        else {
            pos.push_back(arr[i]);
        }
    }

    int ptr1 = 0;
    int ptr2 = 0;
    int idx = 0;
    bool flag = 1;

    while(ptr1 < pos.size() && ptr2 < neg.size()) {
        if (flag) {
            arr[idx++] = pos[ptr1++];
        }
        else {
            arr[idx++] = neg[ptr2++];
        }
        flag = !flag;
    }

    while (ptr1 < pos.size()) {
        arr[idx++] = pos[ptr1++];
    }

    while (ptr2 < neg.size()) {
        arr[idx++] = neg[ptr2++];
    }

    return arr;
}

// TC = O(N)
// SC = O(N)
vector<int> solve_better(vector<int>& arr, int n) {
    vector<int> neg;
    vector<int> pos;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            neg.push_back(arr[i]);
        }
        else {
            pos.push_back(arr[i]);
        }
    }

    if (pos.size() > neg.size()) {
        // handle equal no. of negatives and positives
        for (int i = 0; i < neg.size(); i++) {
            arr[2*i]   = pos[i];
            arr[2*i+1] = neg[i];
        }
        
        // handle remaining positives
        int idx = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++) {
            arr[idx++] = pos[i];
        }
    }
    else {
        // handle equal no. of negatives and positives
        for (int i = 0; i < pos.size(); i++) {
            arr[2*i]   = pos[i];
            arr[2*i+1] = neg[i];
        }
        
        // handle remaining negatives
        int idx = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++) {
            arr[idx++] = neg[i];
        }
    }
    
    return arr;
}

void rotateRight(vector<int>& arr, int outOfPlace, int idx) {
    int temp = arr[idx];
    for (int i = idx; i > outOfPlace; i--) {
        arr[i] = arr[i - 1];
    }
    arr[outOfPlace] = temp;
}

// TC = O(N^2)
// SC = O(1)
vector<int> solve_optimal_with_const_space(vector<int>& arr, int n) {
    int outOfPlace = -1;
    
    for (int i = 0; i < n; i++) {
        if (outOfPlace >= 0) {
            if(((arr[i] >= 0) && (arr[outOfPlace] < 0)) || 
                ((arr[i] < 0 ) && (arr[outOfPlace] >= 0))) {
                
                rotateRight(arr, outOfPlace, i);
            
                if (i - outOfPlace >= 2) {
                    outOfPlace += 2;
                }
                else outOfPlace = -1;    
            } 
        }
        
        if (outOfPlace == -1) {
            // (!(i & 0x01)) -> checks the even index
            // (i & 0x01)    -> checks the odd index
            // -ve no. & at even-place or +ve no. & at odd place
            if (((arr[i]  < 0)  && (!(i & 0x01))) ||
                ((arr[i] >= 0)  &&   (i & 0x01))) {
                outOfPlace = i;
            }
        }
    }

    return arr;
}

vector<int> alternateNumbers(vector<int>&a) {
    // return solve_brute(a, a.size());

    return solve_better(a, a.size());

    // return solve_optimal_with_const_space(a, a.size());
}