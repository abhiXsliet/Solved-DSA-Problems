// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getMajority(vector<int> &nums) {
        int n = nums.size();
        int cntMaj = 0, majEle = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == majEle) cntMaj += 1;
            else {
                cntMaj -= 1;
                if (cntMaj < 0) {
                    cntMaj = 0;
                    majEle = nums[i];
                }
            }
        }
        cntMaj = 0;
        for (int &num : nums) {
            if (num == majEle) {
                cntMaj += 1;
            }
        }
        return (cntMaj >= n/2) ? majEle : -1;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> &tops, vector<int> &bottoms) {
        int n = tops.size();
        unordered_map<int, int> topM, bottomM;
        int topMaxEle = -1, topMaxFreq = -1;
        int bottomEle = -1, bottomFreq = -1;

        for (int i = 0; i < n; i ++) {
            topM[tops[i]] ++;
            bottomM[bottoms[i]] ++;
            if (topM[tops[i]] > topMaxFreq) {
                topMaxFreq = topM[tops[i]];
                topMaxEle  = tops[i];
            }
            if (bottomM[bottoms[i]] > bottomFreq) {
                bottomFreq = bottomM[bottoms[i]];
                bottomEle  = bottoms[i];
            }
        }

        int topAns = 0, bottomAns = 0;
        for (int i = 0; i < n; i ++) {
            if (tops[i] != topMaxEle && topAns != -1) {
                if (bottoms[i] != topMaxEle) topAns = -1;
                else topAns += 1;
            }
            if (bottoms[i] != bottomEle && bottomAns != -1) {
                if (tops[i] != bottomEle) bottomAns = -1;
                else bottomAns += 1;
            }
        }
        if (topAns == -1 && bottomAns == -1) return -1;
        if (topAns == -1 && bottomAns != -1) return bottomAns;
        if (topAns != -1 && bottomAns == -1) return topAns;
        return topAns > bottomAns ? bottomAns : topAns; 
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int> &tops, vector<int> &bottoms) {
        int n = tops.size();
        int topMaxEle = getMajority(tops);
        int bottomEle = getMajority(bottoms);

        int topAns = 0, bottomAns = 0;
        for (int i = 0; i < n; i ++) {
            if (tops[i] != topMaxEle && topAns != -1) {
                if (bottoms[i] != topMaxEle) topAns = -1;
                else topAns += 1;
            }
            if (bottoms[i] != bottomEle && bottomAns != -1) {
                if (tops[i] != bottomEle) bottomAns = -1;
                else bottomAns += 1;
            }
        }
        if (topAns == -1 && bottomAns == -1) return -1;
        if (topAns == -1 && bottomAns != -1) return bottomAns;
        if (topAns != -1 && bottomAns == -1) return topAns;
        return topAns > bottomAns ? bottomAns : topAns; 
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // return approach_1(tops, bottoms);   
        return approach_2(tops, bottoms);   
    }
};