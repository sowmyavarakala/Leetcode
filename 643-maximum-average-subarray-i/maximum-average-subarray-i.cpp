class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0;
        double maxSum = 0;

        for(int i = 0; i < k; i++){
            currSum += nums[i];
        }
        maxSum = currSum;
        for(int i = k; i < nums.size(); i++){
            currSum += nums[i];
            currSum -= nums[i-k];
            maxSum = max(maxSum, currSum);
        }
        cout << maxSum << endl;
        return maxSum/k;
    }
};