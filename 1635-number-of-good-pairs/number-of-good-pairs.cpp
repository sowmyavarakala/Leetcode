class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto x:nums){
            ans += mp[x]++;
        }
        return ans;
    }
};