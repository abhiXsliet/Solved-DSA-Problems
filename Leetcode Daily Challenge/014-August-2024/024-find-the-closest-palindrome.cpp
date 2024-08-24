// https://leetcode.com/problems/find-the-closest-palindrome/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(log(NUM)) ~= O(1)
    // SC : O(1)
    ll getClosestPalin(ll num, bool isOdd) {
        ll temp = num;
        if (isOdd) temp /= 10;

        while (temp) {
            ll rem = (temp % 10);

            // Check if multiplying by 10 would cause overflow
            if (num > LLONG_MAX / 10) {
                return LLONG_MAX;
            }

            num   *= 10;
            num   += rem;
            temp  /= 10;
        }

        return num;
    }
public:
    // TC : O(18) ~= O(1)
    // SC : O(18) ~= O(1)
    string nearestPalindromic(string s) {
        // There are only 5 possibilities for finding the closest palindrome:
        // 1. Palindrome with length original_len - 1, example : 99  closest palin = 101
        // 2. Palindrome with length original_len + 1, example : 101 closest palin = 99
        // For the same length as the original:
        // 3. Palindrome formed by decrementing the middle digits (n - 1)        , example : 345 closest palin = 333
        // 4. Palindrome formed by no change into middle digit, identical as (n) , example : 345 closest palin = 343
        // 5. Palindrome formed by incrementing the middle digits (n + 1)        , example : 345 closest palin = 353

        vector<ll> storeClosestPalindrome(5);
        int len = s.length();

        int L   = len % 2 == 0 ? len / 2 : len / 2 + 1;
        ll num  = stol(s.substr(0, L)); 

        storeClosestPalindrome[0] = (ll)pow(10, len) + 1;               // case 1.
        storeClosestPalindrome[1] = (ll)pow(10, len - 1) - 1;           // case 2.

        // for same length, -1, 0, +1 into middle digit 
        storeClosestPalindrome[2] = getClosestPalin(num - 1, len % 2);  // case 3.
        storeClosestPalindrome[3] = getClosestPalin(num + 0, len % 2);  // case 4.
        storeClosestPalindrome[4] = getClosestPalin(num + 1, len % 2);  // case 5.

        ll diff = LONG_MAX;
        ll res  = LONG_MIN; // closest palindromic number
        ll originalNum = stoll(s);

        for (auto& val : storeClosestPalindrome) {
            // cout << val << " ";
            if (val == originalNum) 
                continue;

            if (abs(val - originalNum) < diff) {
                diff = abs(val - originalNum);
                res  = val;
            } else if (abs(val - originalNum) == diff) {
                res  = min(res, val);
            }
        }
        
        return to_string(res);
    }
};