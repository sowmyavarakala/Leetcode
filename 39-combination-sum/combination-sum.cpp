class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& candidates, vector<int>& curr, int target, int val, int currSum){
        if(currSum > target) return;
        if(currSum == target) {
            result.push_back(curr);
            return;
        }
        for(int i = val; i < candidates.size(); i++){
            currSum += candidates[i];
            curr.push_back(candidates[i]);
            helper(candidates, curr, target, i, currSum);
            curr.pop_back();
            currSum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        helper(candidates, curr, target, 0, 0);
        return result;
    }
};