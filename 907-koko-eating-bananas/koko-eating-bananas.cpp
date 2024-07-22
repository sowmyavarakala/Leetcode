class Solution {
public:
    bool ableToEat(vector<int>& piles, int k, int h){
        int hours = 0;
        for(int& pile: piles){
            hours += (pile + k - 1)/k;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int mid = l + (r-l)/2;
            if(ableToEat(piles, mid, h)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};