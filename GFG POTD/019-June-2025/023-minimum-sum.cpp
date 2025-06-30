// https://www.geeksforgeeks.org/problems/minimum-sum4058/1




#include <bits/stdc++.h>
using namespace std;    

// User function template for C++
class Solution {
  private:
    string summation(string &s1, string &s2) {
        int m = s1.length(), n = s2.length();
        int i = m - 1, j = n - 1;
        int carry = 0;
        string res;
        while (i >= 0 || j >= 0 || carry) {
            int val = carry;
            
            if (i >= 0) {
                val += (s1[i] - '0');
                i --;
            }
            
            if (j >= 0) {
                val += (s2[j] - '0');
                j --;
            }
            
            res  += to_string(val % 10);
            carry = val / 10;
        }
        reverse(begin(res), end(res));
        return res;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    string approach_1(vector<int> &arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int &num : arr) {
            pq.push(num);
        }
        
        string first, second;
        while (!pq.empty()) {
            first += to_string(pq.top());
            pq.pop();
            
            if (pq.empty()) break;
            
            second += to_string(pq.top());
            pq.pop();
        }
        
        string res = summation(first, second);
        res.erase(0, res.find_first_not_of('0'));
        return res;
    }
    
    // TC : O(N)
    // SC : O(N)
    string approach_2(vector<int> &arr) {
        int n = arr.size();
        vector<int> freq(10, 0);
        for (int &num : arr) {
            freq[num] ++;
        }
        
        string first, second;
        for (int i = 0; i < 10; i ++) {
            if (freq[i] == 0) continue;
            
            int half = (freq[i] / 2);
            if (freq[i] % 2) {
                if (first.length() > second.length()) {
                    second += to_string(i);
                } else {
                    first += to_string(i);
                }
            }
            
            if (half == 0) continue;
            string str(half, i + '0');
            
            first  += str;
            second += str;
        }
        
        string res = summation(first, second);
        res.erase(0, res.find_first_not_of('0'));
        return res;
    }
  public:
    string minSum(vector<int> &arr) {
        // return approach_1(arr);
        return approach_2(arr);
    }
};