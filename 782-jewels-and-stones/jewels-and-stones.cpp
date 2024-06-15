class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0; 
        unordered_map<char,int>count;

        for(auto x: stones)
            count[x]++;          

        for(auto x : jewels)
            ans+=count[x];           

        return ans;
    }
};