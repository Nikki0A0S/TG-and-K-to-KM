//https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
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
    TreeNode* root = NULL;
    vector<TreeNode*> levelNodes;
    TreeNode* recoverFromPreorder(string S) {
        int i = 0;
        int sl = S.length();
        while(i < sl) {
            int d = 0;
            int n = 0;
            while(i < sl && S[i] == '-') {
                i++;
                d++;
            }
            while(i < sl && S[i] != '-') {
                n = n*10+S[i]-'0';
                i++;
            }
            if (d == 0) {
                root = new TreeNode(n);
                levelNodes.emplace_back(root);
            } else {
                Insert(n, d, 0);
            }
        }
        return root;
    }
    void Insert(int& n, int d, int l) {
        TreeNode* node = levelNodes[l];
        if (d != 1) {
            Insert(n, d-1, l+1);
        } else {
            TreeNode* newNode = new TreeNode(n);
            if (l+1 < levelNodes.size()) {
                levelNodes[l+1] = newNode;
            } else {
                levelNodes.emplace_back(newNode);
            }
            if (node->left == NULL) {
                node->left = newNode;
            } else {
                node->right = newNode;
            }
        }
    }
};
