//https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        if(matrix.empty() || matrix[0].empty()) return ans;
        vector<vector<int>> vis(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for(int i = 0; i < matrix.size(); ++i){
            dfs(matrix, i, 0, vis, 1);
            dfs(matrix, i, matrix[i].size() - 1, vis, 2);
        }
        for(int i = 0; i < matrix[0].size(); ++i){
            dfs(matrix, 0, i, vis, 1);
            dfs(matrix, matrix.size() - 1, i, vis, 2);
        }
        
        for(int i = 0; i < vis.size(); ++i)
            for(int j = 0; j < vis[i].size(); ++j)
                if(vis[i][j] == 3) ans.push_back(vector<int>{i, j});
        
        return ans;
    }
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    
    void dfs(vector<vector<int>>& mat, int x, int y, vector<vector<int>>& vis, int mask){
        vis[x][y] |= mask;
        for(int k = 0; k < 4; ++k){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx == mat.size() || ny == mat[0].size()) continue;
            if(mat[nx][ny] < mat[x][y] || vis[nx][ny] & mask) continue;
            dfs(mat, nx, ny, vis, mask);
        }
    }
};