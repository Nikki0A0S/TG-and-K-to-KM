//https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end(), greater<int>());
        int i = 0;
        for (; i < k; i++);
        return nums[i - 1];
    }
};