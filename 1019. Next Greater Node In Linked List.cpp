https://leetcode.com/problems/next-greater-node-in-linked-list/
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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> res;
        
        int i = 0;
        
        while(head) {
            res.push_back(head->val);
            while(!st.empty() && res[st.top()] < head->val) {
                res[st.top()] = head->val;
                st.pop();
            }
            st.push(i); 
            i++;
            head = head->next;
        }
        
        while(!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }
        
        return res;
    }
};