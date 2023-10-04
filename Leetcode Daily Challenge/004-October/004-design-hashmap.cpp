// https://leetcode.com/problems/design-hashmap/


#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    vector<int> vec;
    int sz;
    
    MyHashMap() {
        sz = 1e6+1;
        
        vec.resize(sz);
        
        fill(vec.begin(), vec.end(), -1);
    }
    
    void put(int key, int value) {
       vec[key] = value; 
    }
    
    int get(int key) {
       return vec[key] ;
    }
    
    void remove(int key) {
      vec[key]  =-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */