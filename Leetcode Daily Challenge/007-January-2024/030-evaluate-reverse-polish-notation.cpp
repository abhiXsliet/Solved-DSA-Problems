
// https://leetcode.com/problems/evaluate-reverse-polish-notation/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int operate(int& num1, int& num2, string& token) {
        if (token == "+") return num2 + num1;
        if (token == "-") return num2 - num1;
        if (token == "*") return (long)num2 * (long)num1;
        if (token == "/") return num2 / num1;
        return -1;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_approach_1(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();

                result = operate(num1, num2, token);

                st.push(result);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    } 

    // TC : O(N)
    // SC : O(N)
    int solve_approach_2(vector<string>& tokens) {
        stack<int> st;
        int result = 0;

        unordered_map<string, function<int(int, int)> > mpp = {
            {"+", [](int a, int b) {return a + b;} }, 
            {"-", [](int a, int b) {return b - a;} }, 
            {"*", [](int a, int b) {return (long)a * (long)b;} }, 
            {"/", [](int a, int b) {return b / a;} }
        };

        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();

                result = mpp[token](num1, num2);

                st.push(result);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }    
public:
    int evalRPN(vector<string>& tokens) {
        // return solve_approach_1(tokens);

        return solve_approach_2(tokens);
    }
};