class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> st(nums1.begin(),nums1.end());
        for(auto x : nums2){
            if(st.erase(x)) res.push_back(x);
        }
        return res;
    }
};