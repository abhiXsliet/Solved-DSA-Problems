// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/



#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC = O(N)
    // SC = O(N)
    bool solve_brute(vector<string>& word1, vector<string>& word2) {
        string merge1 = "", merge2 = "";
        
        for (string str : word1) 
            merge1 += str;

        for (string str : word2)
            merge2 += str;

        return merge1 == merge2;
    }

    // TC = O(N)
    // SC = O(1)
    bool solve_optimal(vector<string>& word1, vector<string>& word2) {
        int n = word1.size();
        int m = word2.size();

        int i = 0, j = 0, a = 0, b = 0;

        while (i < n && j < m) {
            if (word1[i][a++] != word2[j][b++]) 
                return false;

            if (a == word1[i].size()) a = 0, i++;
            if (b == word2[j].size()) b = 0, j++;
        }

        return i == n && j == m;
    }
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // return solve_brute(word1, word2);

        return solve_optimal(word1, word2);
    }
};