// https://leetcode.com/problems/grumpy-bookstore-owner/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) Where N = Size of Customers or Grumpy Array 
    // SC : O(1) 
    int approach_1(vector<int>& customers, vector<int>& grumpy, int min) {
        int n = customers.size();
        long satisfiedCustomers = 0;
        for (int i = 0; i < n; i ++) {
            if (!grumpy[i]) {
                satisfiedCustomers += customers[i];
            }
        }

        int left = 0, right = left;
        long unSatisfied = satisfiedCustomers;
        
        while (right < n) {
            while ((right - left + 1) <= min) {
                if (grumpy[right])
                    unSatisfied += customers[right];
                right   += 1;
            }
            
            satisfiedCustomers = max(satisfiedCustomers, unSatisfied);

            if ((right - left) == min) {
                if (grumpy[left]) {
                    unSatisfied -= customers[left];
                }
                left += 1;
            }
        }
        
        return satisfiedCustomers;
    }

    // TC : O(N) Where N = Size of Customers or Grumpy Array 
    // SC : O(1) 
    int approach_2(vector<int>& customers, vector<int>& grumpy, int min) {
        // INTUTION : Find the count of maxm unsatisfied customers by taking a window of size 'minutes',
        //            So that you can use the power of minutes to satisfy them.
        // Answer   : Maxm unsatisfied customers in window of minutes + Satisfied Customers 
        
        int n = customers.size();
        int currUnsatisfied = 0;   // current unsatisfied customers in initial window size of minute

        for (int i = 0; i < min; i ++) {
            currUnsatisfied += customers[i] * grumpy[i];
        }

        int maxUnsatisfied = currUnsatisfied;
        int l = 0, r = min;
        
        while (r < n) {
            currUnsatisfied += customers[r] * grumpy[r];    // adding new element in window
            currUnsatisfied -= customers[l] * grumpy[l];    // removing element from the window, maintain minutes size

            maxUnsatisfied  = max(maxUnsatisfied, currUnsatisfied);
            l ++, r ++;
        }

        int power = maxUnsatisfied;    // Using power maxUnsatisfied customers can be satisfied
        int satisfiedCus = 0;
        for (int i = 0; i < n; i ++) {
            satisfiedCus += customers[i] * (1 - grumpy[i]);
        }

        return (satisfiedCus + power);
    }
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // return approach_1(customers, grumpy, minutes);  

        return approach_2(customers, grumpy, minutes);
    }
};