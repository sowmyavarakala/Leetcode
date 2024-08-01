class Solution {
public:
    int find(vector<int>& nums, int& target, int n, int curr){
        if(n == 0){
            if(target == curr){
                return 1;
            }
            return 0;
        }
        return find(nums, target, n - 1, curr + nums[n-1]) + find(nums, target, n - 1, curr - nums[n-1]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return find(nums, target, nums.size(), 0);
    }
};