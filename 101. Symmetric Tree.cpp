//https://leetcode.com/problems/symmetric-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
private:
    
    bool checkSymmetric(TreeNode* subTree1, TreeNode* subTree2) {
        if (!subTree1 && !subTree2) return true;
        if (subTree1 && subTree2) {
            return ((subTree1->val == subTree2->val) 
					&& checkSymmetric(subTree1->left, subTree2->right)
                    && checkSymmetric(subTree2->left, subTree1->right));
        }
        return false; 
    }
    
    
public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || checkSymmetric(root->left, root->right);
    }
};