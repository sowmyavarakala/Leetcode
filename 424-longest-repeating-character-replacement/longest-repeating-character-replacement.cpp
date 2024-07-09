class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, ans = 0, finalResult = 0;
        unordered_map<int,int> mp;

        for(int r = 0; r < s.length(); r++){
            mp[s[r]]++;
            ans = max(ans, mp[s[r]]);
            if(r-l+1 - ans > k){
                mp[s[l++]]--;
            }
            finalResult = max(finalResult, r-l+1);
        }
        return finalResult;
    }
};