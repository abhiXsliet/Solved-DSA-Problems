// https://leetcode.com/contest/weekly-contest-414/problems/convert-date-to-binary/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    string convertDateToBinary(string date) {
        stringstream ss(date);
        string str;
        string res;

        while(getline(ss, str, '-')) {
            int data = stoi(str);
            string binary;
            while(data) {   
                int rem = data % 2;
                binary = to_string(rem) + binary;
                data /= 2;
            }

            if (!res.empty()) {
                res += "-";
            }
            res += binary;
        }

        return res;
    }
};
