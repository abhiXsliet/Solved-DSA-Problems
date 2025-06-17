// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(log(num))
    // SC : O(log(num))
    int maxDiff(int num) {
        string a = to_string(num);
        string b = to_string(num);

        int idx = a.find_first_not_of('9');
        if (idx != string::npos) {
            char ch = a[idx];
            replace(begin(a), end(a), ch, '9');
        }
        
        for (int i = 0; i < b.length(); i ++) {
            if (i > 0 && b[i] != b[0] && b[i] != '0') {
                char ch = b[i];
                replace(begin(b), end(b), ch, '0');
                break;
            } else if (b[0] != '1'){
                char ch = b[0];
                replace(begin(b), end(b), ch, '1');
                break;
            }
        }

        return stoi(a) - stoi(b);
    }
};