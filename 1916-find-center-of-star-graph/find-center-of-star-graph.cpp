class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> count(edges.size()+2,0);
        for(auto t :  edges){
            count[t[0]]++;
            count[t[1]]++;
        }
        for( int i = 1; i <= edges.size()+1; i++){
            if(count[i] == edges.size())
                return i;
        }
        return -1;
    }
};