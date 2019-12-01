//https://leetcode.com/problems/find-bottom-left-tree-value/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
            int res;
        if (!root) return res;
        que.push(root);
        int count=1;
        vector<int> tmp;
        while(!que.empty())
        {
                tmp.push_back(que.front()->val);
                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right) que.push(que.front()->right);
                que.pop();
                count--;
                if (!count)
                {
                        count=que.size();
                        res=tmp[0];
                        tmp.clear();
                }
        }
        return res;
    }
};