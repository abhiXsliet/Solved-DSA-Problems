// https://leetcode.com/problems/design-task-manager/



// TC : O(rows) for constructor, O(L) for getValue() where L = formula.length()
class Spreadsheet {
    int[][] sheet;
    public Spreadsheet(int rows) {
        sheet = new int[rows][26];
    }
    
    public void setCell(String cell, int value) {
        int c = cell.charAt(0) - 'A';
        int r = Integer.parseInt(cell.substring(1)) - 1;
        sheet[r][c] = value;
    }
    
    public void resetCell(String cell) {
        int c = cell.charAt(0) - 'A';
        int r = Integer.parseInt(cell.substring(1)) - 1;
        sheet[r][c] = 0;
    }

    public int solve(String str) {
        if (Character.isDigit(str.charAt(0))) {
            return Integer.parseInt(str);
        }

        int c = str.charAt(0) - 'A';
        int r = Integer.parseInt(str.substring(1)) - 1;
        return sheet[r][c];
    }
    
    public int getValue(String formula) {
        int plusIdx = formula.indexOf('+');

        String left  = formula.substring(1, plusIdx);
        String right = formula.substring(plusIdx + 1);

        return solve(left) + solve(right);
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */