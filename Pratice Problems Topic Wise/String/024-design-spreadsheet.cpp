// https://leetcode.com/problems/design-spreadsheet/




#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    pair<int, int> getCoordinates(string &cell) {
        int col = (cell[0] - 'A');
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }

    int evaluate(string term) {
        int val = 0;
        if (!isdigit(term[0])) {
            auto [r, c] = getCoordinates(term);
            val = grid[r][c];
        } else {
            val = stoi(term);
        }
        return val;
    }
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [r, c] = getCoordinates(cell);
        grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r, c] = getCoordinates(cell);
        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        int i_plus = formula.find('+');
        string left  = formula.substr(1, (i_plus - 1));
        string right = formula.substr(i_plus + 1);

        return evaluate(left) + evaluate(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */