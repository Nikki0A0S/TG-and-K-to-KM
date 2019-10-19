https://leetcode.com/problems/redundant-connection/
class Solution {
public:
    vector <int> g[1005];
    bool vis[1005];
    map < pair<int, int>, int > m;
    
    int dfs(int x, int parent) {
        vis[x] = true;
        
        for(int i=0;i<g[x].size();i++) {
            if(!vis[g[x][i]]) {
                int k = dfs(g[x][i], x); 
                if(k == 0) // No Cycle
                    continue;
                else {
                    m[{ min(x, g[x][i]), max(x, g[x][i]) }] = 1;
                    if(k == x) 
                        return 0;
                    return k; 
                }
                
            }
            else if(parent != g[x][i]) {  
                m[{ min(x, g[x][i]), max(x, g[x][i]) }] = 1;
                return g[x][i];
            }
        }
        return 0;  // No Cycle found return 0
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0], v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        dfs(1, -1);
        
        vector <int> ans;
        
        for(int i=edges.size()-1;i>=0;i--) {
            if(m[{ edges[i][0], edges[i][1] }] != 0) {
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                break;
            }
        }
        
        return ans;
    }
};