class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, i = 0, r =0;
        for(int i = 1; i < nums.size(); i++){
            nums[i] = max(nums[i-1], nums[i]+i);
        }
        while(i < nums.size()-1){
            jumps++;
            i = nums[i];
        }
        return jumps;
    }
};