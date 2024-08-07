// https://leetcode.com/problems/integer-to-english-words/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> below_20 { ""       , "One"    , "Two"      , "Three"   , "Four"    , 
                                "Five"   , "Six"    , "Seven"    , "Eight"   , "Nine"    , 
                                "Ten"    , "Eleven" , "Twelve"   , "Thirteen", "Fourteen", 
                                "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens     { "", "", "Twenty", "Thirty" , "Forty" , "Fifty", 
                                    "Sixty" , "Seventy", "Eighty", "Ninety" };
    vector<string> thousand { "", " Thousand", " Million", " Billion" };
    string solve(int n) {
        if (n == 0) return "";
        else if (n < 20 ) return below_20[n];
        else if (n < 100) return tens[n / 10] + (n % 10 ? " " + solve(n % 10) : "");
        else return below_20[n / 100] + " Hundred" + (n % 100 ? " " + solve(n % 100) : "");
    }
public:
    // TC : O(1) Limited digits (at most 10 for a 32-bit integer).
    //           Solve function called a constant 4 times, each handling at most 3 digits.
    // SC : O(1) Fixed space for string representations, integers, and strings.
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i = 0;
        string words = "";
        // Divide the number into chunks of 3 digits and convert each chunk into words
        while (num > 0) {
            if (num % 1000 != 0) {
                words = solve(num % 1000) + thousand[i] + (words.empty() ? "" : " ") + words;
            }
            num /= 1000;
            i ++;
        }
        return words;
    }
};