class Solution {
public:
    void helper(vector<vector<int>>& result,vector<int>& current,vector<int>& candidates, int target, int currentVal, int currentSum){
        if(currentSum > target) return;
        if(currentSum == target) {
            result.push_back(current);
            return;
            }
        for(int i = currentVal; i<candidates.size(); i++){
            if(i>currentVal && candidates[i] == candidates[i-1]) continue;
            currentSum += candidates[i];
            current.push_back(candidates[i]);
            helper(result, current, candidates, target,i+1,currentSum);
            current.pop_back();
            currentSum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        helper(result, current, candidates, target,0,0);
        return result;
    }
};