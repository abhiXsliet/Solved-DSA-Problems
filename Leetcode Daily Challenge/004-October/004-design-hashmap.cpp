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


// --------------------------------- OPTIMAL ------------------------------------------------------------------
class MyHashMap
{
public:
  vector<list<pair<int, int>>> buckets;
  int size;
  MyHashMap()
  {
    size = 10000;
    buckets.resize(size);
  }

  int getIndex(int key)
  { // a simple hash function
    return key % size;
  }

  void put(int key, int value)
  {
    int bucket_no = getIndex(key);
    list<pair<int, int>> &chain = buckets[bucket_no];

    for (auto &it : chain)
    {
      if (it.first == key)
      { // if found then update value of key
        it.second = value;
        return;
      }
    }
    chain.emplace_back(key, value);
  }

  int get(int key)
  {
    int bucket_no = getIndex(key);
    list<pair<int, int>> &chain = buckets[bucket_no];

    if (chain.empty())
      return -1;

    for (auto &it : chain)
    {
      if (it.first == key)
      {
        return it.second;
      }
    }
    return -1;
  }

  void remove(int key)
  {
    int bucket_no = getIndex(key);
    list<pair<int, int>> &chain = buckets[bucket_no];

    if (chain.empty())
      return;

    for (list<pair<int, int>>::iterator it = chain.begin(); it != chain.end(); it++)
    {
      if (it->first == key)
      {
        chain.erase(it);
        return;
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */