//https://leetcode.com/problems/path-sum/
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
    
    bool hasPathSumHelper(TreeNode* root, int currentSum, int sum) {
        if (currentSum + root->val == sum && !root->left && !root->right) return true; 
        return ((root->left) ? hasPathSumHelper(root->left, currentSum + root->val, sum) : false) ||
                ((root->right) ? hasPathSumHelper(root->right, currentSum + root->val, sum) : false);
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return (!root) ? 0 : hasPathSumHelper(root, 0, sum);
    }
};