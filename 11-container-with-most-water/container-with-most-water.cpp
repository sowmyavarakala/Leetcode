class Solution {
public:
    int maxArea(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int area = 0;
        while(l<r){
            int w = r-l;
            area = max(area, w* min(nums[l],nums[r]));
            if(nums[l]>nums[r]){
                r--;
            }else if(nums[l]<nums[r]){
                l++;
            }
            else{
                l++;
                r--;
            }
        }
        return area;
    }
};