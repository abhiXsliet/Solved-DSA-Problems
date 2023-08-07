// https://leetcode.com/contest/biweekly-contest-110/problems/insert-greatest-common-divisors-in-linked-list/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    int gcd(int a, int b){

        if(a == 0)
            return b;

        if(b == 0)
            return a;

        while (a != b)
        {
            if( a > b){
                a = a-b;
            }else {
                b = b-a;
            }
        }
        return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int> l;
        ListNode* temp = head;
        while(temp != NULL) {
            l.push_back(temp -> val);
            temp = temp -> next;
        }
        // for(auto& i:l) cout << i << " " ;
        
        vector<int>gcdVal;
        int idx1 = 0, idx2 = 1;
        while(idx2 < l.size()) {
            int val = gcd(l[idx1], l[idx2]);
            gcdVal.push_back( val );
            idx1++;
            idx2++;
        }

        ListNode* curr = head -> next;
        ListNode* prev = head;
        int index = 0;
        while(curr != NULL && gcdVal.size() != 0) {
            ListNode* nodeToInsert = new ListNode(gcdVal[index]);
            prev -> next = nodeToInsert;
            nodeToInsert -> next = curr;
            prev = curr;
            curr = curr -> next;
            index++;
        }
        
        // for(auto& i:gcdVal) cout << i << " " ;
        return head;
    }
};