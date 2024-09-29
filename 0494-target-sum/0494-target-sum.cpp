class Solution {
public:
    void solve(vector<int>& nums, int target, int index, int currentSum, int& count) {
        if (index == nums.size()) {
            if (currentSum == target) {
                count++;
            }
            return;
        }
        solve(nums, target, index + 1, currentSum + nums[index], count);
        solve(nums, target, index + 1, currentSum - nums[index], count);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        solve(nums, target, 0, 0, count);
        return count;
    }
};
