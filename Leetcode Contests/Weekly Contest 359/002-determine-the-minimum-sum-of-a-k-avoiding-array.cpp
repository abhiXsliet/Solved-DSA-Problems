// https://leetcode.com/contest/weekly-contest-359/problems/determine-the-minimum-sum-of-a-k-avoiding-array/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        
        vector<int> store(max(n, k));
        int el  = 1;
        for(int i = 0;  i < max(n, k); i++) {
            store[i] = el;
            el++;
        }

        unordered_set<int> newStore;
        for(int i = 0; i < max(n, k); i++) {
            for(int j = i+1; j < max(n, k); j++) {
                if(store[i] + store[j] == k) {
                    newStore.insert(store[j]);
                }
            }
        }

        vector<int> ans;
        int num = 1;
        while (ans.size() != n) {
            if( newStore.find(num) != newStore.end() ) 
                    num++;
            else ans.push_back(num++);
        }

        int sum = 0;
        for(int i = 0; i < ans.size(); i++) {
            sum += ans[i];
        }
        return sum;
    }
};