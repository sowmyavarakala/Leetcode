class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                int x = st.top();
                st.pop();
                ans[x] = i - x;
            }
            st.push(i);
        }
        return ans;
    }
};