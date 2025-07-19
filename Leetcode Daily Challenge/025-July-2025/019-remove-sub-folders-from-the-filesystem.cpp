// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<string> approach_1(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> result;
        unordered_set<string> st;
        for (string &fold : folder) {
            string prefix;
            bool isSubfolder = 0;
            for (char &ch : fold) {
                if (ch == '/' && st.count(prefix)) {
                    isSubfolder = 1;
                    break;
                }
                prefix += ch;
            }
            if (!isSubfolder) {
                st.insert(fold);
                result.push_back(fold);
            }
        }
        return result;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    vector<string> approach_2(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> result;
        for (string &fold : folder) {
            if (result.empty() || fold.find(result.back()) != 0 || fold[result.back().size()] != '/') {
                result.push_back(fold);
            }
        }
        return result;
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // return approach_1(folder);
        return approach_2(folder);   // No Extra Space
    }
};