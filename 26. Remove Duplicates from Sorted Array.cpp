//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if(nums.size()==0)return 0;
        vector<int>::iterator p= nums.begin(),q = nums.begin();
        int count=1;
        for(p=nums.begin()+1;p!=nums.end();p++){
            if(*p!=*q){*(++q)=*p;count++;}
            
        }
        return count; 
    }
};