class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& nums, vector<bool>& visited, vector<int>& path){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                path.push_back(nums[i]);
                visited[i] = true;
                helper(nums, visited, path);
                visited[i] = false;
                path.pop_back();
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        helper(nums, visited, path);
        return result;
    }
};