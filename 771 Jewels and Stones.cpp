//https://leetcode.com/problems/jewels-and-stones/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int k;
        k=0;
        for (auto i: J){
            for (auto j : S){
                if (i==j){
                    ++k;
                }
            }
        }
        return k;
    }
};