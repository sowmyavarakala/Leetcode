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
        int dp[nums.size() + 1][target + 1];
        for(int i = 0; i <= nums.size(); i++) 
            dp[i][0] = 1;
        
        // initializing first row by 0 (from second elemnt i.e index = 1)
        for(int i = 1; i <= target; i++) 
            dp[0][i] = 0;

        for(int i = 1; i <= nums.size(); i++)
            for(int j = 0; j <= target; j++)
                if(nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
        return dp[nums.size()][target];
    }
};