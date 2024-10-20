// https://leetcode.com/problems/parsing-a-boolean-expression/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    char solveOperator(char &op, vector<char>& chStore) {
        if (op == '!') return chStore[0] == 't' ? 'f' : 't';

        if (op == '|') {
            // for (char& ch : chStore) {
            //     if (ch == 't') return 't';
            // }
            // return 'f';

            return any_of(begin(chStore), end(chStore), [](char ch) { return ch == 't'; }) ? 't' : 'f'; // one liner
        }

        // else op == '&'
        // for (char& ch : chStore) {
        //     if (ch == 'f') return 'f';
        // }
        // return 't';

        return any_of(chStore.begin(), chStore.end(), [](char ch) { return ch == 'f'; }) ? 'f' : 't';
    }
public:
    // TC : O(N)
    // SC : O(N) Where N = expression length
    bool parseBoolExpr(string expression) {
        stack<int> stk;
        for (char &ch : expression) {
            if (ch == ',') continue;
            if (ch == ')') {
                vector<char> charStore;
                while (stk.top() != '(') {
                    charStore.push_back(stk.top());
                    stk.pop();
                }

                stk.pop(); // '('
                
                // Operators : '!', '|', '&'
                char op = stk.top();
                stk.pop();

                stk.push(solveOperator(op, charStore));
            } else {
                stk.push(ch);
            }
        }
        return stk.top() != 'f';
    }
};