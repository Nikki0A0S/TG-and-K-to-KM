https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        fillInorder(root, res);
        return res;
    }
    
    void fillInorder(TreeNode* root, vector<int>& arr)
    {
        if(root == nullptr)
            return;
        
        fillInorder(root->left, arr);
        arr.push_back(root->val);
        fillInorder(root->right, arr);
    }
};