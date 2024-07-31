class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        while(n){
            if(n % 2) result = n > 0 ? result = result * x : result / x;
            x = x * x;
            n = n/2;
        }
        return result;
    }
};