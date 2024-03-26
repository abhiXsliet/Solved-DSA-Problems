// https://leetcode.com/problems/design-hashset/



#include <bits/stdc++.h>
using namespace std;

// ------------------------------ BRUTE ----------------------------------------------------

class MyHashSet {
public:
    vector<bool> store;
    MyHashSet() {
        store.resize(1000001, 0);
    }
    
    void add(int key) {
        store[key] = 1;
    }
    
    void remove(int key) {
        store[key] = 0;
    }
    
    bool contains(int key) {
        return store[key] == 1;
    }
};


// ------------------------ OPTIMAL ---------------------------------------------------------
// Implemented Using SEPARATE CHAINING APPROACH

class MyHashSet {
public:
    int M;
    vector<list<int>> store;

    int getIndex(int key) {
        return key % M;
    }

    MyHashSet() {
        M     = 10000;
        store = vector<list<int>>(M, list<int>{});
    }
    
    void add(int key) {
        int idx = getIndex(key);

        auto itr = find(store[idx].begin(), store[idx].end(), key);

        if (itr == store[idx].end()) {
            store[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = getIndex(key);

        auto itr = find(store[idx].begin(), store[idx].end(), key);

        if (itr != store[idx].end()) {
            store[idx].erase(itr);
        }
    }
    
    bool contains(int key) {
        int idx = getIndex(key);

        auto itr = find(store[idx].begin(), store[idx].end(), key);

        return itr != store[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */