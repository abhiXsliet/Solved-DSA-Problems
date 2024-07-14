// https://leetcode.com/problems/number-of-atoms/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef unordered_map<string, int> MAP;

    // TC : O(N^2)
    // SC : O(N)    Where N = formula length
    string countOfAtoms(string formula) {
        int n = formula.length();
        
        stack<MAP> st;
        st.push(MAP());

        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                st.push(MAP());
                i++;
            } else if (formula[i] == ')') {
                MAP currMap = st.top();
                st.pop();
                i++;

                string multiplier;
                while (i < n && isdigit(formula[i])) {
                    multiplier += formula[i];
                    i++;
                }

                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                for (auto& [atom, count] : currMap) {
                    st.top()[atom] += count;
                }
            } else {
                string currAtom;
                currAtom += formula[i];
                i++;

                while (i < n && islower(formula[i])) {
                    currAtom += formula[i];
                    i++;
                }

                string digit;
                while (i < n && isdigit(formula[i])) {
                    digit += formula[i];
                    i++;
                }

                int count = digit.empty() ? 1 : stoi(digit);
                st.top()[currAtom] += count;
            }
 
        }
        
        map<string, int> sortedMap(begin(st.top()), end(st.top()));

        string result;
        for (auto& [atom, count] : sortedMap) {
            result += atom;
            if (count > 1) {
                result += to_string(count);
            }
        }

        return result;
    }
};