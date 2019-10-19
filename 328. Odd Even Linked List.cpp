https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == 0) return 0;
        ListNode* odd = head, *s_even = head->next, *even = head->next;
        
        while(odd && even){
            odd->next = even->next;
            if(odd->next == 0){
                odd->next = s_even;
                even->next = 0;
                break;
            }
            odd = odd->next;
            even->next = odd->next;
            if(even->next == 0){
                odd->next = s_even;
                break;
            }
            even = even->next;
        }
        
        return head;
    }
};