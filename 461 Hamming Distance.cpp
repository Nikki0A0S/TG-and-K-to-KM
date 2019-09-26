//https://leetcode.com/problems/power-of-three/ 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        while (x > 0 || y > 0) {
            if (x % 2 != y % 2) {   
                result++;
            }
			x /= 2; 
            y /= 2;
        }
        return result;  
    }
};