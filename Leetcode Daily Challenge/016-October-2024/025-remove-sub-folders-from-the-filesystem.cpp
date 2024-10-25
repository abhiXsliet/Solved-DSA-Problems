// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N)) Where N = No. of strings
    // SC : O(K)        Where K = Unqiue folders only & no subfolders
    vector<string> brute(vector<string>& folder) {
        sort(begin(folder), end(folder));
        unordered_set<string> st;
        vector<string> result;
        for (string& fold : folder) {
            string prefix;
            bool isSubfolder = 0;
            for (int i = 0; i < fold.length(); i ++) {
                if (fold[i] == '/') {
                    if (st.count(prefix)) {
                        isSubfolder = 1;
                        break;
                    }
                }
                prefix += fold[i];
            }
            if (!isSubfolder) {
                result.push_back(prefix);
                st.insert(prefix);
            }
        }
        return result;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    vector<string> optimal(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> result;
        for (string &fold : folder) {
            if (result.empty() || 
                fold.compare(0, result.back().size(), result.back()) != 0 ||
                fold[result.back().size()] != '/') {    // instead of compare, we can also use : fold.find(result.back()) != 0
                result.push_back(fold);
            }
        }
        return result;
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // return brute(folder);    // store in set and check subfolder at '/'

        return optimal(folder);  // no auxiliary space used
    }
};