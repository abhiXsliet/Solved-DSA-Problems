// https://leetcode.com/problems/design-memory-allocator/




#include <bits/stdc++.h>
using namespace std;

class Allocator {
public:
    vector<int> memory;
    int cap;
    Allocator(int n) {
        cap = n;
        memory.resize(n, 0);
    }
    
    int allocate(int size, int mID) {
        int i = 0, j = 0, sum = 0, ansIdx = -1;
        while (j < cap) {
            sum += memory[j];
            if (j - i + 1 == size) {
                if (sum == 0) {
                    // allocate and return
                    ansIdx = i;
                    break;
                } else {
                    sum -= memory[i];
                    i ++;
                }
            }
            j ++;
        }
        
        if (ansIdx == -1) return ansIdx;

        // allocating
        for (int i = ansIdx; i < cap && i < ansIdx + size; i ++) {
            memory[i] = mID;
        }

        return ansIdx;
    }
    
    int freeMemory(int mID) {
        int count = 0;
        for (int i = 0; i < cap; i ++) {
            if (memory[i] == mID) {
                memory[i] = 0;
                count += 1;
            }
        }
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */