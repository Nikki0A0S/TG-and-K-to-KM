//https://leetcode.com/problems/delete-nodes-and-return-forest/

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
   void tag(TreeNode*& root, vector<int>& to_delete, vector<TreeNode*>& res, TreeNode* parent = NULL)
{
	if (root)
	{
		for (int i = 0; i < to_delete.size(); i++)
			if (0 == (root->val *= !(to_delete[i] == root->val)))
				break;
		tag(root->left, to_delete, res, root);
		tag(root->right, to_delete, res, root);
		if (root->val != 0 && (parent == NULL || parent->val == 0))
			res.push_back(root);

		if (root->val == 0)
		{
			root = NULL;
		}
	}
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
{
	vector<TreeNode*> res;
	tag(root, to_delete, res);
	return res;
}
};