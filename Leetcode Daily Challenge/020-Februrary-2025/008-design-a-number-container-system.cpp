// https://leetcode.com/problems/design-a-number-container-system/




#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
public:
    unordered_map<int, set<int>> numToIndices;   // stores all indices corresponding to a number into a set {num, {indices}}
    unordered_map<int, int> idxWithNum;          // stores all number with its corresponding indices {num, idx}
    NumberContainers() {}
    
    void change(int index, int number) {
        if (idxWithNum.count(index)) {  // replace
            int prevNum = idxWithNum[index];

            // remove index from numToIndices[prevNum] set
            numToIndices[prevNum].erase(index);
            if (numToIndices[prevNum].empty()) {
                numToIndices.erase(prevNum);
            }
        }
        numToIndices[number].insert(index);
        idxWithNum[index] = number;
    }
    
    int find(int number) {
        if (numToIndices.count(number)) {
            return *numToIndices[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */