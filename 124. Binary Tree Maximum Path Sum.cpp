//https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int maxPathSum(TreeNode *root, int &max)
{
	if(root==NULL)
        return 0;

    int l=maxPathSum(root->left, max);
    int r=maxPathSum(root->right, max);
    
    int sum=root->val;  
    if(l>0)
        sum+=l;
    if(r>0)
        sum+=r;
    if(max<sum)            
        max=sum;
    
    if(r>l and r>0)         
        return root->val+r;
    else if( l > 0)
        return root->val+l;
 
    return root->val;
}
int maxPathSum(TreeNode* root) {

    int max=root->val;
    maxPathSum(root, max);

    return max;
}
};