//https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
};

bool Solution::canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	unordered_map<int, vector<int> > edges;
	int *cnts, cnt, course;
	unordered_map<int, vector<int> >::iterator it;
	queue<int> q;
	
	if (numCourses == 0 || prerequisites.size() == 0)
		return true;
	
	cnts = new int[numCourses]();
	cnt = 0;
	
	for (int i = 0; i < prerequisites.size(); i++) {
		it = edges.find(prerequisites[i][0]);
		if (it == edges.end()) {
			vector<int> temp;
			temp.push_back(prerequisites[i][1]);
			edges.insert(make_pair(prerequisites[i][0], temp));
		} else {
			it->second.push_back(prerequisites[i][1]);
		}
		cnts[prerequisites[i][1]]++;
	}
	
	for (int i = 0; i < numCourses; i++) {
		if (cnts[i] == 0) {
			q.push(i);
		} 
	}
		
	while (!q.empty()) {
		course = q.front();
		q.pop();
		cnt++;
		
		it = edges.find(course);
		if (it == edges.end())
			continue;
		for (int i = 0; i < it->second.size(); i++) {
			cnts[it->second[i]]--;
			if (cnts[it->second[i]] == 0) {
				q.push(it->second[i]);
			}
		}	
	}
	
	if (cnt == numCourses)
		return true;
	return false;
}