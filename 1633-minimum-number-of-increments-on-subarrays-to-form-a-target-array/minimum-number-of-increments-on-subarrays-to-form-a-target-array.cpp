class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int num = target[0];

        for(int i = 1; i < target.size(); i++){
            if(target[i] > target[i-1]){
                num += target[i] - target[i-1];
            }
        }
        return num;
    }
};

//https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/solutions/3958420/short-intuitive-code-explained-c-code-greedy-approach/?envType=company&envId=google&favoriteSlug=google-thirty-days