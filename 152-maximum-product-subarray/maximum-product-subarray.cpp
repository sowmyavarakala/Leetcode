class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxProd = nums[0];
        int minProd = nums[0];
        int maxi = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            maxi = max(maxi, maxProd);
        }
        
        return maxi;
    }
};