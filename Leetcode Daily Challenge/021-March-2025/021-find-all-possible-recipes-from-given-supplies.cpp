// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> topoSort(vector<string> &recipes, unordered_map<string, vector<int>> &adj, vector<int> &indegree) {
        queue<int> q;
        for (int i = 0; i < indegree.size(); i ++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<string> result;

        while (!q.empty()) {
            int rIdx = q.front();   // recipes idx which is independent
            q.pop();

            result.push_back(recipes[rIdx]);

            for (auto &nbr : adj[recipes[rIdx]]) {
                indegree[nbr] --;
                if (!indegree[nbr]) {
                    q.push(nbr);
                }
            }
        }

        return result;
    }

    // TC : O(S*Ls + R*R*I*Li + R*Lr) S and R are the number of supplies and recipes, while Ls, Li, and Lr are the average lengths of supply, ingredients, and recipes
    // SC : O(S*Ls + R) 
    vector<string> approach_1(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies) {
        int R = recipes.size(), I = ingredients.size(), S = supplies.size();
        vector<string> result;
        unordered_set<string> st(begin(supplies), end(supplies));   // supplies
        vector<bool> recipeState(R, 0);
        
        int count = R;
        while (count --) {
            // Traverse again on recipeState to check which receipes can be made
            for (int i = 0; i < R; i ++) {
                if (recipeState[i]) 
                    continue;
                
                bool canMade = 1;
                for (int j = 0; j < ingredients[i].size(); j ++) {  // O(I)
                    string reqIng = ingredients[i][j];
                    if (!st.count(reqIng)) {    // O(Li)
                        canMade = 0;
                        break;
                    }
                }
                if (canMade) {
                    st.insert(recipes[i]);
                    result.push_back(recipes[i]);
                    recipeState[i] = true;
                }
            }
        }
        return result;
    }

    // TC : O(S*Ls + (R + I*Li))
    // SC : O(S*Ls + R)
    vector<string> approach_2(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int R = recipes.size(), I = ingredients.size(), S = supplies.size();

        unordered_set<string> st(begin(supplies), end(supplies));
        unordered_map<string, vector<int>> adj;     // {"ingredient" -> {}}
        vector<int> indegree(R, 0);

        for (int i = 0; i < R; i ++) {  // O(R)
            for (int j = 0; j < ingredients[i].size(); j ++) {  // O(I)
                string reqIngr = ingredients[i][j];
                if (!st.count(reqIngr)) {   // O(Li)
                    adj[reqIngr].push_back(i);
                    indegree[i] ++;
                }
            }
        }

        return topoSort(recipes, adj, indegree);
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // return approach_1(recipes, ingredients, supplies);
        return approach_2(recipes, ingredients, supplies);
    }
};