//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> level(i, 1);
            
            for (int j = 1; j < i - 1; j++)
            
                level[j] = res[i-2][j-1] + res[i-2][j];
            
            res.push_back(level);
        }

        return res;
    }
};