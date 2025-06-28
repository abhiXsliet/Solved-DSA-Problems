// https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<char> &arr, int k) {
        int n = arr.size();
        
        queue<int> thief, police;
        int totalCaught = 0;
        
        for (int i = 0; i < n; i ++) {
            if (arr[i] == 'P') 
                police.push(i);
            else 
                thief.push(i);
                
            while (!thief.empty() && !police.empty()) {
                if (abs(thief.front() - police.front()) <= k) {
                    totalCaught += 1;
                    thief.pop();
                    police.pop();
                } else {
                    if (thief.front() < police.front())
                        thief.pop();
                    else
                        police.pop();
                }
            }
        }
        
        return totalCaught;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<char> &arr, int k) {
        int n = arr.size();
        
        int i = 0, j = 0;   // police and thief pointers
        int totalCaught = 0;
        
        while (i < n && j < n) {
            while (i < n && arr[i] != 'P') i ++;
            while (j < n && arr[j] != 'T') j ++;
            
            if (i < n && j < n) {
                if (abs(j - i) <= k) {
                    i ++, j ++, totalCaught ++;
                } else {
                    if (i < j) i ++;
                    else j ++;
                }
            }
        }
        
        return totalCaught;
    }
  public:
    int catchThieves(vector<char> &arr, int k) {
        // return approach_1(arr, k);
        return approach_2(arr, k);
    }
};