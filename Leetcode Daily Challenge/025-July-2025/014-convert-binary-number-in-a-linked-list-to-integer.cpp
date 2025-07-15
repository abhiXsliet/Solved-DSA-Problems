// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/




#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimal = 0;
        ListNode* temp = head;
        while (temp) {
            decimal = (decimal * 2) + temp -> val;
            temp = temp -> next;
        }
        return decimal;
    }
};