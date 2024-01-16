// https://leetcode.com/problems/insert-delete-getrandom-o1/



#include <bits/stdc++.h>
using namespace std;

// --------------------------------- BRUTE FORCE SOLUTION ------------------------------------------------------------------------------------------------
// TC : O(1)
// SC : O(N)
class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) == st.end()) {
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (st.find(val) != st.end()) {
            st.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        // vector<int> vec(begin(st), end(st));
        // int randNum = rand() % vec.size();
        // return vec[randNum];

        auto it = st.begin();
        // Advances the iterator (it) by a random number of positions within the set
        advance(it, rand() % st.size());
        return *it;
    }
};

/* *
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj =  new RandomizedSet();
 * bool param_1 = obj -> insert(val);
 * bool param_2 = obj -> remove(val);
 * int param_3  = obj -> getRandom();
 */