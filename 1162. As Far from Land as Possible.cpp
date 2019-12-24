//https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
	int n = grid.size();
	vector<vector<int>> visited(n, vector<int>(n,0));
	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
	queue<vector<int>> q;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(grid[i][j] == 1) {
				q.push({i,j});
				dist[i][j] = 0;
			}
		}
	}
	vector<int> dx = {1,-1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};
	int res = -1;
	while(q.size()) {
		int x = q.front()[0];
		int y = q.front()[1];
		q.pop();
		for(int d=0; d<4; d++) {
			int i=x+dx[d];
			int j=y+dy[d];
			if(i<0 || j<0 || i>=n || j>=n || grid[i][j] || visited[i][j]) continue;
			visited[i][j] = 1;
			dist[i][j] = min(dist[i][j], dist[x][y]+1);
			res = max(res, dist[i][j]);
			q.push({i,j});
		}
	}
	return res==INT_MAX ? -1 : res;
}
};