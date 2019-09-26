//https://leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(n<0) x = 1.0/x;
        double kisik= n%2==0?1.0:x;
        n/=2;
        while(n!=0){
            x*=x;
            if(n%2!=0) kisik*=x;
            n/=2;
        }
        return kisik;
    }
};