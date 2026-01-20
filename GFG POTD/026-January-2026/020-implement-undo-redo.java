// https://www.geeksforgeeks.org/problems/implement-undo-redo/1/




import java.util.*;

class Solution {
    StringBuilder str = new StringBuilder();
    StringBuilder removed = new StringBuilder();
    
    public void append(char x) {
        str.append(x);
    }

    public void undo() {
        if (str.length() > 0) {
            char ch = str.charAt(str.length() - 1);
            str.deleteCharAt(str.length() - 1);
            removed.append(ch);
        }
    }

    public void redo() {
        if (removed.length() > 0) {
            char ch = removed.charAt(removed.length() - 1);
            removed.deleteCharAt(removed.length() - 1);
            str.append(ch);
        }
    }

    public String read() {
        return str.toString();
    }
}
