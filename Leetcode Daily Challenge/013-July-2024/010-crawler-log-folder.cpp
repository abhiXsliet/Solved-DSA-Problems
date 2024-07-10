// https://leetcode.com/problems/crawler-log-folder/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M*N) Where M = logs array size & N = Max Length of Individual String
    // SC : O(1)
    int approach_1(vector<string>& logs) {
        int depth = 0;
        for (auto& log : logs) {
            int n   = log.size();
            int dot = 0;
            for (int i = n - 2; i >= 0; i --) {
                if (log[i] >= '0' && log[i] <= '9' ||
                    log[i] >= 'a' && log[i] <= 'z') {
                    depth += 1;
                    break;
                }
                if (i - 1 >= 0 && log[i - 1] == '.') {
                    dot += 1; 
                }
            }
            depth = depth >= dot ? depth - dot : 0;
        }
        return depth;
    }

    // TC : O(M) Where M = logs array size
    // SC : O(1)
    int approach_2(vector<string>& logs) {
        int depth = 0;
        for (auto& log : logs) {
            int n   = log.size();
            int dot = 0;
            if (log[n - 2] >= '0' && log[n - 2] <= '9' ||
                log[n - 2] >= 'a' && log[n - 2] <= 'z') {
                depth += 1;
            }
            if (log[0] == '.' && log[n - 2] == '.') {
                dot = (n - 2); 
            }
            depth = depth >= dot ? depth - dot : 0;
        }
        return depth;
    }

    // TC : O(M) Where M = logs array size
    // SC : O(1)
    int approach_3(vector<string>& logs) {
        int depth = 0;
        for (auto& log : logs) {
            if (log == "../")
                depth = max(0, depth - 1);
            else if (log == "./") 
                continue;
            else depth ++;
        }
        return depth;
    }

    // TC : O(M) Where M = logs array size
    // SC : O(N) Where N = Length of Individual Strings
    int approach_4(vector<string>& logs) {
        stack<string> stk;
        for (auto& log : logs) {
            if (log != "../" && log != "./")
                stk.push(log);
            else if (log == "../")
                if (!stk.empty()) stk.pop();
        }
        return stk.size();
    }
public:
    int minOperations(vector<string>& logs) {
        // return approach_1(logs);     // Brute
        // return approach_2(logs);     // Better
        // return approach_3(logs);     // Better : Different writing style
        return approach_4(logs);        // Using Stack
    }
};