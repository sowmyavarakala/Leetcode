class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currSum = 0;
        int maxSum = 0;

        for(int i = 0; i < gain.size(); i++){
            currSum += gain[i];
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};