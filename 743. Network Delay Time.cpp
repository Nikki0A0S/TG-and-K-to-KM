https://leetcode.com/problems/network-delay-time/
class Solution {
    typedef pair<int, int> pir;    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<pir> g[N+1];
        for(vector<int> v : times) {
            g[v[0]].push_back({v[1], v[2]});
            //g[v[0]].insert({v[1], v[2]});
        }
        
        const int inf = 1e9;
        vector<int> dist(N+1, inf);
        dist[K] = 0;
        
        priority_queue<pir, vector<pir>, greater<pir>> pq;
        pq.push({0, K});
        
        vector<bool> v = vector(N+1, false);
        while(!pq.empty()) {
            pir node = pq.top(); pq.pop();
            int cur = node.second;
            if(v[cur]) continue;
            for(auto& to : g[node.second]) {
                int v = to.first, w = to.second;
                if(dist[cur] + w < dist[v]) {
                    dist[v] = dist[cur] + w;
                    pq.push({dist[v], v});
                }
            }
            v[cur] = true;
        }
        
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
    }
};