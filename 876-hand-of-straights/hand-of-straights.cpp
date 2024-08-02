class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }
        
        map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        
        for (auto& [num, count] : countMap) {
            if (count > 0) {
                for (int i = 1; i < k; ++i) {
                    if (countMap[num + i] < count) {
                        return false;
                    }
                    countMap[num + i] -= count;
                }
            }
        }
        return true;
    }
};