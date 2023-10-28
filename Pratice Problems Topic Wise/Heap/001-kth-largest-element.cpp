// https://www.codingninjas.com/studio/problems/k-largest-element_1062624?leftPanelTab=1



#include <bits/stdc++.h> 
using namespace std;

// TC = O(N*log(N) + K*log(N))
vector<int> solve_brute(vector<int>& a, int k, int n) {
    priority_queue<int> pq; // MAX-HEAP

    // n*log(n)
    for(int& i: a)
        pq.push(i);

    vector<int> ans;
    
    // k*log(n)
    while(k--) {
        int ele = pq.top();
        pq.pop();
        ans.push_back(ele);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// TC = O(N*log(K))
vector<int> solve_better(vector<int>& a, int k, int n) {
    vector<int>ans;
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int& i : a) {
        pq.push(i);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// TC = O(N)
vector<int> solve_optimal(vector<int>& a, int k, int n) {
    vector<int> result;
    sort(a.begin(), a.end());

    for (int i = n - 1; i >= 0; i--) {
        if(result.size() != k)
            result.push_back(a[i]);
    }
    reverse(begin(result), end(result));
    return result;
}

vector<int> Klargest(vector<int> &a, int k, int n) {
    // return solve_brute(a, k, n);

    // return solve_better(a, k, n);

    return solve_optimal(a, k, n);
}