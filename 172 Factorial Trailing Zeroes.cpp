//https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) {
        int five_count = 0;
        int exponent = 1;
        long divide = 5;
        int division;
        
        while((division = n / divide) > 0){
            five_count += division;
            divide *= 5;
        }
               
        return five_count;
    }
};