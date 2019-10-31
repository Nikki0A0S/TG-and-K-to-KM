//https://leetcode.com/problems/broken-calculator/
class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X >= Y) {
            return X - Y;
        }
        int ans = 0;
        while(X < Y) {
            ans += 1;
           if(Y % 2 == 1) {
               Y++;
               continue;
           }
            Y = Y / 2;
        }
        return ans + X - Y;
        
    }
};