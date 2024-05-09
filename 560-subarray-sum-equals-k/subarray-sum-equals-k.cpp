class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp = {{0,1}};
        int sum = 0, count = 0;
        for(auto n:nums){
            sum += n;
            count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};