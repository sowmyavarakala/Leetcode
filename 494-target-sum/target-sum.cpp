class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum - target < 0 || (sum - target) % 2 != 0){
            return 0;
        }
        target = (sum - target) / 2;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        // Fill the DP table
        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }

        return dp[target];
    }
};