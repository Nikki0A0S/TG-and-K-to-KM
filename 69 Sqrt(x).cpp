//https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        long long start = 1;
        long long end = x;
        long long temp = 0;
        while(start <= end){
            long long mid = start + (end- start)/2;
            long long val = mid*mid;
            if(val == x)
                return mid;
            if(val < x){
                temp = mid;
                start = mid+1;
            }else
                end = mid-1;
        }
        return temp;
    }
};