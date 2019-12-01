//https://leetcode.com/problems/employee-importance/

class Solution {
private:
    void dfs(unordered_map<int, Employee*>& employees, int& importanceSum, int id) {
        importanceSum += employees[id]->importance;
        for (int idx = 0; idx < employees[id]->subordinates.size(); ++idx)
            dfs(employees, importanceSum, employees[id]->subordinates[idx]);        
    }
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int, Employee*> mapEmployees;
        for (int i = 0; i < employees.size(); ++i)
            mapEmployees[employees[i]->id] = employees[i];
        
        int sum = 0;
        dfs(mapEmployees, sum, id);
        
        return sum;
    }
};