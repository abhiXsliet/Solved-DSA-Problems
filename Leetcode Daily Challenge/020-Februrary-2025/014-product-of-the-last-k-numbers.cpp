// https://leetcode.com/problems/product-of-the-last-k-numbers/




#include <bits/stdc++.h>
using namespace std;

// --------------------------------------- BRUTE ------------------------------------------------------------------------------------------------

// TC : O(n^2)
// SC : O(n) : for stream
class ProductOfNumbers {
public:
    vector<int> storeNumbers;
    ProductOfNumbers() {}
    
    void add(int num) {
        storeNumbers.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        for (int i = storeNumbers.size() - 1; i >= 0 && i >= storeNumbers.size() - k; i --) {
            ans *= storeNumbers[i];
        }
        return ans;
    }
};

// ------------------------------------- BETTER --------------------------------------------------------------------------------------------------
// TC : O(1) for add function
// TC : O(log(n)) for getProduct function
// SC : O(n + n) for storeNumbers + zeroIndices
class ProductOfNumbers {
public:
    vector<int> storeNumbers;
    vector<int> zeroIndices;  // keeps the indices at which zeros occurs
    ProductOfNumbers() {}
    
    void add(int num) {
        if (storeNumbers.empty()) {
            storeNumbers.push_back(num);
            if (num == 0) zeroIndices.push_back(storeNumbers.size() - 1);
        } else {
            int val = storeNumbers.back();
            val *= num;
            if (num == 0) {
                zeroIndices.push_back(storeNumbers.size()); // indices at which zero is occuring
                storeNumbers.push_back(num);
            } else {
                if (val == 0) {
                    storeNumbers.push_back(num);
                } else {
                    storeNumbers.push_back(val);
                }
            }
        }
    }
    
    int getProduct(int k) {
        int prevIdx = storeNumbers.size() - k - 1;
        if (prevIdx < 0) {
            return zeroIndices.empty() ? storeNumbers.back() : 0;
        }
        if (binarySearch(zeroIndices, prevIdx)) {    // search is there any index greater than prevIdx 
            return 0;
        }

        int val  = storeNumbers.back();
        int prev = storeNumbers[prevIdx];

        if (prev) {
            return val / prev;
        }
        return val;
    }

    bool binarySearch(vector<int>& arr, int tarIdx) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > tarIdx) {
                return true;
            } else if (arr[mid] <= tarIdx) {
                low = mid + 1;
            }
        }
        return false;
    }
};

// ------------------------------------- BETTER --------------------------------------------------------------------------------------------------

// TC : O(log(n)) for add function
// TC : O(1) for getProduct function 
// SC : O(n + n) for storeNumbers + zeroIndices
class ProductOfNumbers {
public:
    vector<int> storeNumbers;
    priority_queue<int> zeroIndices;  // keeps the indices at which zeros occurs
    ProductOfNumbers() {}
    
    void add(int num) {
        if (storeNumbers.empty()) {
            storeNumbers.push_back(num);
            if (num == 0) zeroIndices.push(storeNumbers.size() - 1);
        } else {
            int val = storeNumbers.back();
            val *= num;
            if (num == 0) {
                zeroIndices.push(storeNumbers.size()); // indices at which zero is occuring
                storeNumbers.push_back(num);
            } else {
                if (val == 0) {
                    storeNumbers.push_back(num);
                } else {
                    storeNumbers.push_back(val);
                }
            }
        }
    }
    
    int getProduct(int k) {
        int prevIdx = storeNumbers.size() - k - 1;
        if (prevIdx < 0) {
            return zeroIndices.empty() ? storeNumbers.back() : 0;
        }
        if (!zeroIndices.empty() && zeroIndices.top() > prevIdx) {    // search is there any index greater than prevIdx 
            return 0;
        }

        int val  = storeNumbers.back();
        int prev = storeNumbers[prevIdx];

        if (prev) {
            return val / prev;
        }
        return val;
    }
};

// ------------------------------------- OPTIMAL --------------------------------------------------------------------------------------------------

// TC : O(1) for both functions
// SC : O(N) for stream
class ProductOfNumbers {
public:
    vector<int> storeNumbers;
    int n;
    ProductOfNumbers() {
        storeNumbers.clear();
        n = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            storeNumbers = {};
            n = 0;
        } else {
            if (storeNumbers.empty()) {
                storeNumbers.push_back(num);
            } else {
                storeNumbers.push_back(storeNumbers.back() * num);
            }
            n ++;
        }
    }
    
    int getProduct(int k) {
        if (k > n) 
            return 0;
        if (k == n) 
            return storeNumbers[n - 1];
        return storeNumbers[n - 1] / storeNumbers[n - k - 1];
    }
};
    

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */