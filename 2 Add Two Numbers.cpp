//https://leetcode.com/problems/factorial-trailing-zeroes/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* resultNode = new ListNode(0);
        ListNode* currentNode = resultNode;
        
        while (l1 or l2) {
            int temp = 0;
            if (l1) {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                temp += l2->val;
                l2 = l2->next;
            }
            
            temp += carry;
            carry = temp > 9 ? 1 : 0;
            temp = temp % 10;
            currentNode->next = new ListNode(temp);
            currentNode = currentNode->next;
        }
        
        if (carry) {
            currentNode->next = new ListNode(carry);
        }
    }
};
