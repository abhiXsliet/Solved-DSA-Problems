// https://leetcode.com/problems/count-vowel-strings-in-ranges/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    // TC : O(N^2) -> TLE since left(li) could be 0 and right(ri) could be words.size();
    // SC : O(1)
    vector<int> solve_brute(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = words.size();

        vector<int> result(n, 0);
        
        for (int i = 0; i < n; i++) {
            int left  = queries[i][0];
            int right = queries[i][1];
            int cnt   = 0;

            for (int j = left; j <= right; j++) {
                string str = words[j];

                if (isVowel(str[0]) && isVowel(str[str.length() - 1])) {
                    cnt ++;
                }
            }
            result[i] = cnt;
        }

        return result;
    }

    // TC : O(M) where M is the size of the words array
    // SC : O(M)
    vector<int> solve_optimal(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = words.size();

        // store the no. of words of given condn. till that index
        vector<int> prefixSum(m, 0);
        if (isVowel(words[0][0]) && isVowel(words[0][words[0].length() - 1])) 
            prefixSum[0] = 1;
        else 
            prefixSum[0] = 0;

        for (int i = 1; i < m; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].length() - 1])) 
                prefixSum[i] += prefixSum[i - 1] + 1;
            else 
                prefixSum[i] += prefixSum[i - 1];
        }

        vector<int> result(n, 0);
        
        for (int i = 0; i < n; i++) {
            int left  = queries[i][0];
            int right = queries[i][1];

            int cnt;
            if (left == 0) 
                cnt = prefixSum[right];
            else 
                cnt = prefixSum[right] - prefixSum[left - 1];

            result[i] = cnt;
        }

        return result;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // return solve_brute(words, queries);

        return solve_optimal(words, queries);
    }
};