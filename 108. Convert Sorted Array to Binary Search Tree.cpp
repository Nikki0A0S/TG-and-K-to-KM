https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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

TreeNode* Construct(vector<int> &nums, int s, int e)
{
    
    if(s>e)
        return NULL;
    
    if(s-e==0)
        return new TreeNode(nums[s]);
    
    int mid = s+ (e-s+1)/2;
    TreeNode * root= new TreeNode(nums[mid]);
    
    root->left=Construct(nums, s, mid-1);
    root->right=Construct(nums, mid+1, e);
    
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    
    return Construct(nums, 0, nums.size()-1);

}
};