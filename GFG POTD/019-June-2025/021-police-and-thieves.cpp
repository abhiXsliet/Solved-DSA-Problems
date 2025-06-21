// https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int catchThieves(vector<char>& arr, int k) {
        int n = arr.size();
        queue<int> police, thief;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') {
                police.push(i);
            } else if (arr[i] == 'T') {
                thief.push(i);
            }

            while (!police.empty() && !thief.empty()) {
                if (abs(police.front() - thief.front()) <= k) {
                    count++;
                    police.pop();
                    thief.pop();
                } else {
                    // Remove the one that is behind (cannot catch anyone now)
                    if (police.front() < thief.front())
                        police.pop();
                    else
                        thief.pop();
                }
            }
        }

        return count;
    }
};