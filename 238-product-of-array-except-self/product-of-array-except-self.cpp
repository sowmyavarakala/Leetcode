class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> product(n);
        product[0] = 1;
        for(int i=1;i<n;i++){
            product[i] =  nums[i-1] * product[i-1];
        }
        int right = 1;
        for(int i=n-1;i>=0;i--){
            product[i] *= right;
            right *= nums[i];
        }
        return product;
    }
};