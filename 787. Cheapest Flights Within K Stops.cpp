//https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>>m(n,vector<int>(n,0));
        for(auto f:flights){
            m[f[0]][f[1]] = f[2];
        }        
        queue<int>Q({src});
        vector<int>minPrices(n,INT_MAX); //record the min prices from src-->to i
        minPrices[src] = 0;
        int count = -1;
        while(!Q.empty() && count < K){   
            count++;
            int size = Q.size();
            for(int k = 0;k < size;k++){
                int x = Q.front();Q.pop();
                for(int c = 0;c < n;c++){
                    if(m[x][c] && minPrices[c] > minPrices[x]+m[x][c]){
                        if(count < K || c==dst) //do not update minPrices
                            minPrices[c] = minPrices[x]+m[x][c];
                        Q.push(c);
                    }
                }
            }
        }
        
        if(minPrices[dst]==INT_MAX)
            return -1;
        return minPrices[dst];        
    }
};