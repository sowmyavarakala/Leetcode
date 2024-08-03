class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        bool canX = false, canY = false, canZ = false;

        for(auto triplet: triplets){
            int a = triplet[0], b = triplet[1], c = triplet[2];
            if(a <= x && b <= y && c <= z){
                if(a == x) canX = true;
                if(b == y) canY = true;
                if(c == z) canZ = true;
            }
        }
        return canX && canY && canZ;
    }
};