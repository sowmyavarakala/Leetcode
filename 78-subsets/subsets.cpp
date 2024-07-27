class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& nums, int val, vector<int>& curr){
        result.push_back(curr);
        for(int i = val; i < nums.size(); i++){
            curr.push_back(nums[i]);
            helper(nums, i + 1, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        helper(nums, 0, curr);
        return result;
    }
};