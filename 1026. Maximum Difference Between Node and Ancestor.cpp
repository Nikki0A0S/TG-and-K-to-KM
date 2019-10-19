https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
public:
    int maxAncestorDiff(TreeNode* root) {
        return go(root, root->val, root->val);
    }
    int go(TreeNode* root, int mini, int maxi) {
        if (!root)
            return maxi - mini;
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        return max(go(root->left, mini, maxi), go(root->right, mini, maxi));
    }
};