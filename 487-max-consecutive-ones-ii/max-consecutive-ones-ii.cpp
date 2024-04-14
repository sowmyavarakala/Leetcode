class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int flipped = 0, unflipped = 0;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]) {
                flipped++;
                unflipped++;
            } else {
                res = max(res, flipped);
                flipped = unflipped+1;
                unflipped = 0;
            }
        }
        
        res = max(res, flipped);
        return res;
    }
};