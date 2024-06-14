class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i=0,j=0,ans =0, result = 0;

        for(j=0;j<s.length();j++){
            mp[s[j]]++;

            ans = max(ans,mp[s[j]]);
            if((j-i+1) - ans > k){
                mp[s[i]]--;
                i++;
            }
            result = max(result, j-i+1);

        }
        return result;
    }
};