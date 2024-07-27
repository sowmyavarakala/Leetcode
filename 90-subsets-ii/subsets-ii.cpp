
class Solution {
public:
    vector<vector<int>> subset;
    void getHelper(vector<int>& nums, int val, vector<int>& current){
        subset.push_back(current);
        for(int i = val;i<nums.size();i++){
            if(i>val && nums[i] == nums[i-1]) continue;
            current.push_back(nums[i]);
            getHelper(nums,i+1,current);
            current.pop_back();
        }
        
    }
   

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        sort(nums.begin(),nums.end());
        getHelper(nums,0,current);
        return subset;
    }
};