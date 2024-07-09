class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp.push(nums[i]);
            if(mp.size()>k) mp.pop();
        }
        return mp.top();
    }
};