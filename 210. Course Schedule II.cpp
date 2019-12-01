//https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
};

vector<int> Solution::findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
	vector<int> ans;
	vector<int> inCnt(numCourses, 0);
	vector<bool> visit(numCourses, false);
	vector<vector<int>> edges(numCourses, vector<int>());
	queue<int> q;
	
	for (int i = 0; i < prerequisites.size(); i++) {
		edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
		inCnt[prerequisites[i][0]]++;
	}
	
	for (int i = 0; i < inCnt.size(); i++) {
		if (inCnt[i] == 0) {
			visit[i] = true;
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int course = q.front(); q.pop();
		ans.push_back(course);
		
		for (int i = 0; i < edges[course].size(); i++) {
			int nextCourse = edges[course][i];
			if (visit[nextCourse] == false) {
				inCnt[nextCourse]--;
				if (inCnt[nextCourse] == 0) {
					visit[nextCourse] = true;
					q.push(nextCourse);
				}
			}
		}
	}
	
	if (ans.size() != numCourses)
		ans.clear();
		
	return ans;
}