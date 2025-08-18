// https://leetcode.com/problems/24-game/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const double epsilon = 1e-2;

    // TC : O(1)
    // SC : O(1)
    bool solve(vector<double> &cards) {
        if (cards.size() == 1) {
            return abs(24 - cards[0]) <= epsilon;
        }

        for (int i = 0; i < cards.size(); i ++) {
            for (int j = 0; j < cards.size(); j ++) {
                if (i == j) continue;

                vector<double> temp;    // stores the remaining elements other than cards[i], cards[j]
                for (int k = 0; k < cards.size(); k ++) {
                    if (k != i && k != j) {
                        temp.push_back(cards[k]);
                    }
                }

                double a = cards[i], b = cards[j];

                vector<double> operations {a + b, a - b, b - a, a * b};

                if (abs(b) > 0.0) {
                    operations.push_back(a / b);
                }

                if (abs(a) > 0.0) {
                    operations.push_back(b / a);
                }

                for (double val : operations) {
                    temp.push_back(val);
                    if (solve(temp)) return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int &val : cards) {
            nums.push_back(1.0 * val);
        }
        return solve(nums);
    }
};