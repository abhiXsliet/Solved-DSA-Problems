// https://leetcode.com/problems/number-of-senior-citizens/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int way_1(vector<string>& details) {
        int passengerCnt = 0;
        int n = details.size();
        for (int i = 0; i < n; i ++) {
            string s;
            s += details[i][11];
            s += details[i][12];
            int age = stoi(s);
            if (age > 60) 
                passengerCnt ++;
        }
        return passengerCnt;
    }

    // TC : O(N)
    // SC : O(1)
    int way_2(vector<string>& details) {
        int passengerCnt = 0;
        int n = details.size();
        for (string detail : details) {
            char tens = detail[11];
            char ones = detail[12];
            if (tens > '6' || (tens == '6' && ones > '0')) 
                passengerCnt ++;
        }
        return passengerCnt;
    }
public:
    int countSeniors(vector<string>& details) {
        // return way_1(details);

        return way_2(details);  // No use of stoi()
    }
};