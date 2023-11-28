// https://leetcode.com/problems/design-a-text-editor/



#include <bits/stdc++.h>
using namespace std;

// Time and space complexity hinge on operation sequence and frequency. 
// Excluding stack space, the complexity is O(n), with n being the total added characters.
class TextEditor {
public:
    stack<int> lStk;
    stack<int> rStk;
    TextEditor() {
        
    }
    
    // TC = O(N)
    // SC = O(N) -> pushed to left stack
    void addText(string text) {
        for (int i = 0; i < text.length(); i++) {
            lStk.push(text[i]);
        }
    }
    
    // TC = O(K)
    // SC = O(1)
    int deleteText(int k) {
        int deletedChar = 0;
        
        while(!lStk.empty() && k--) {
            lStk.pop();
            deletedChar ++;
        }

        return deletedChar;
    }
    
    // TC = O(K)
    // SC = O(1)
    string cursorLeft(int k) {
        while (!lStk.empty() && k--) {
            char ch = lStk.top();
            lStk.pop();
            rStk.push(ch);
        }

        return leftOfCursor();
    }
    
    // TC = O(K)
    // SC = O(1)
    string cursorRight(int k) {
        while(!rStk.empty() && k--) {
            char ch = rStk.top();
            rStk.pop();
            lStk.push(ch);
        }

        return leftOfCursor();
    }

    // TC = O(1)
    // SC = O(1)
    string leftOfCursor() {
        int lSize = lStk.size();
        int val   = 10;
        int mini  = min(val, lSize);

        string ans = "";

        // O(10) -> max
        while (!lStk.empty() && mini--) {
            ans += lStk.top();
            lStk.pop();
        }

        reverse(begin(ans), end(ans));

        // O(10) -> max
        for (int i = 0; i < ans.size(); i++) {
            lStk.push(ans[i]);
        }

        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */