// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(log(num))
    // SC : O(log(num))
    int minMaxDifference(int num) {
        string a = to_string(num);
        string b = to_string(num);

        int idx = a.find_first_not_of('9');
        if (idx != string::npos) {
            char ch = a[idx];
            replace(begin(a), end(a), ch, '9');
        }

        char ch = b[0];
        replace(begin(b), end(b), ch, '0');

        return stoi(a) - stoi(b); 
    }
};