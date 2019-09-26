//https://leetcode.com/problems/hamming-distance/
class Solution {
public:
    int fib(int N) {
        if (N <=1) {
            return N;
        }
        if (N ==2) {
            return 1;
        }
        int result =0;
        int a1=1;
        int a2=1;
        for (int i=3; i<=N; ++i){
            result=a1+a2;
            a2=a1;
            a1=result;
        }
        return result;
    }
};