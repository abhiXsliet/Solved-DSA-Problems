// https://leetcode.com/problems/design-task-manager/




#include <bits/stdc++.h>
using namespace std;

// TC : O(rows) for constructor, O(L) for getValue() where L = formula.length()
class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {
        sheet.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1)) - 1;
        sheet[r][c] = value;
    }
    
    void resetCell(string cell) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1)) - 1;
        sheet[r][c] = 0;
    }

    int solve(string &str) {
        if (isdigit(str[0])) {
            return stoi(str);
        }

        int c = str[0] - 'A';
        int r = stoi(str.substr(1)) - 1;
        return sheet[r][c];
    }
    
    int getValue(string formula) {
        int plusIdx = formula.find_first_of('+');
    
        string left  = formula.substr(1, plusIdx - 1);
        string right = formula.substr(plusIdx + 1); 

        return solve(left) + solve(right);   
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */