// https://leetcode.com/problems/maximum-compatibility-score-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getScore(vector<int> &student, vector<int> &mentor) {
        int score = 0;
        for (int i = 0; i < student.size(); i ++) {
            if (student[i] == mentor[i]) score += 1;
        }
        return score;
    }
public:
    // TC : O(M! * M)
    // SC : O(M^2)
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();

        vector<vector<int>> possibleScore(m, vector<int>(m, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < m; j ++) {
                possibleScore[i][j] = getScore(students[i], mentors[j]);
            }
        }

        vector<int> perm(m);
        iota(begin(perm), end(perm), 0);    // [0, 1, 2, ... ,m - 1]
        
        int maxScore = 0;
        
        do {
            int total = 0;
            for (int i = 0; i < m; i ++) {
                total += possibleScore[i][perm[i]];
            }
            maxScore = max(maxScore, total);
        } while (next_permutation(begin(perm), end(perm)));

        return maxScore;
    }
};