//https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return judge(root->left, NULL, root) && judge(root->right, root, NULL);
    }
    
    bool judge(TreeNode* tp, TreeNode* min, TreeNode* max){
        if(!tp) return true;
        if((min != NULL && tp->val <= min->val) || (max != NULL && tp->val >= max->val))
            return false;
        return judge(tp->left, min, tp) && judge(tp->right, tp, max);
    }
};