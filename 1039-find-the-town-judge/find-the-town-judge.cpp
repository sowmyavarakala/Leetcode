class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1)
        return trust.empty() ? 1 : -1;

        vector<int> trusted_by(n+1,0);
        vector<int> trusts(n+1,0);

        for(auto t :  trust){
            trusts[t[0]]++;
            trusted_by[t[1]]++;
        }
        for( int i = 1; i <= n; i++){
            if(trusts[i] == 0 && trusted_by[i] == n - 1){
                return i;
            }
        }
        return -1;
    }
};