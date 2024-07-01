class Solution {
public:
    int countSubstrings(string s) {
         if (s.length() <= 1) {
            return 1;
        }
        int ans = 0;
        std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));
        for (int i = 0; i < s.length(); ++i) {
        dp[i][i] = true;
        ans++;
        for (int j = 0; j < i; ++j) {
            if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                dp[j][i] = true;
                ans++;
        }
    }
}
return ans;

        
    }
};