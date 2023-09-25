// https://leetcode.com/problems/find-the-difference/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:

    // TC = O(N), SC = O(N)
    char solve_brute(string s, string t) {
        unordered_map<char, int> mpp;

        for(char &ch : s) 
            mpp[ch]++;

        for (char &ch : t) {
            mpp[ch]--;
            
            if (mpp[ch] < 0) 
                return ch; 
        }
        return 'n'; // code execution will never come here
    }
    
    // TC = O(N), SC = O(1)
    char solve_better_1(string s, string t) {
        int sum_s = 0;
        int sum_t = 0;

        for (char &ch : s) 
            sum_s += ch;
        
        for (char &ch : t)
            sum_t += ch;

        return (char)(sum_t - sum_s);
    }

    // TC = O(N), SC = O(1)
    char solve_better_2(string s, string t) {
        int sum = 0;
        for (char &ch : t) 
            sum += ch;

        for (char &ch : s)  
            sum -= ch;

        return (char)sum;
    }

    // TC = O(N), SC = O(1)
    char solve_optimal(string s, string t) {
        int XOR = 0;
        for (char &ch : s) 
            XOR ^= ch;

        for (char &ch : t)
            XOR ^= ch;

        return (char)XOR;
    }
public:
    char findTheDifference(string s, string t) {
        // return solve_brute(s, t);

        // return solve_better_1(s, t);

        // return solve_better_2(s, t);

        return solve_optimal(s, t);
    }
};