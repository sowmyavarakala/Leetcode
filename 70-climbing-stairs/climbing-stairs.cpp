class Solution {
public:
    int climbStairs(int n) {
        if(n<=3){
            return n;
        }
        int n2=2,n3=3,ans=0;
        for(int i=4;i<=n;i++){
            ans = n2+n3;
            n2= n3;
            n3 = ans;
        }
        return ans;
    }
};