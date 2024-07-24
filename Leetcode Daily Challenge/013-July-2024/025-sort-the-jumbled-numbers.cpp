// https://leetcode.com/problems/sort-the-jumbled-numbers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getMappedNumber(int num, vector<int>& mapping) {
        if (num < 10) return mapping[num];
        int mappedNum = 0;
        int placeVal  = 1;
        while (num) {
            int idx    = num % 10;
            int mapDig = mapping[idx];
            mappedNum += (placeVal * mapDig);
            placeVal  *= 10;
            num       /= 10;
        }
        return mappedNum;
    }

    // TC : O(D)
    // SC : O(D) Where D = No. of digits present in nums
    string getMappedNum(int num, vector<int>& mapping) {
        string originalNum  = to_string(num);
        string mappedNum;
        for (int i = 0; i < originalNum.length(); i ++) {
            int chIdx  = originalNum[i] - '0';
            mappedNum += mapping[chIdx] + '0';
        }
        return mappedNum;
    }

    // TC : O(N*D + N*logN) Where N = Total No. present in array nums
    // SC : O(N + D)        Where D = Maximum No. of digits in a number
    vector<int> approach_1(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;     // {mappingNum, idx of original num}

        for (int i = 0; i < n; i ++) {  // O(n)
            string mappedNum = getMappedNum(nums[i], mapping);  // O(d)
            int mappedNumber = stoi(mappedNum);
            vec.push_back({mappedNumber, i});
        }

        sort(begin(vec), end(vec)); // O(n*log(n))

        vector<int> result;
        for (auto& p : vec) {
            result.push_back(nums[p.second]);
        }
        return result;
    }

    // TC : O(N*log(D) + N*logN) Where N = Total No. present in array nums
    // SC : O(N + D)             Where D = Maximum No. of digits in a number
    vector<int> approach_2(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;     // {mappingNum, idx of original num}

        for (int i = 0; i < n; i ++) {  // O(n)
            int mappedNumber = getMappedNumber(nums[i], mapping);
            vec.push_back({mappedNumber, i});
        }

        sort(begin(vec), end(vec)); // O(n*log(n))

        vector<int> result;
        for (auto& p : vec) {
            result.push_back(nums[p.second]);
        }
        return result;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // return approach_1(mapping, nums);    // Converting each no. into String

        return approach_2(mapping, nums);       // without string conversion
    }
};