// https://leetcode.com/problems/fraction-to-recurring-decimal/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    string fractionToDecimal(int numr, int deno) {
        if (numr == 0) return "0";

        string result;
        if ((ll)numr * deno < 0) {
            result += "-";
        } 

        ll absNumr = labs(numr);
        ll absDeno = labs(deno);

        ll div  = absNumr / absDeno;
        result += to_string(div);   // log10(div)
        
        ll rem  = absNumr % absDeno;
        if (rem == 0) return result;

        result += '.';
        unordered_map<int, int> mpp;

        // TC : O(deno + length)
        while (rem) {
            if (mpp.count(rem)) {   // one time
                result.insert(mpp[rem], "(");  // O(length)  
                result += ")";
                break;
            }

            mpp[rem] = result.length();
            
            rem *= 10;
            
            int digit = rem / absDeno;
            result += to_string(digit);

            rem = rem % absDeno;
        }

        return result;
    }
};