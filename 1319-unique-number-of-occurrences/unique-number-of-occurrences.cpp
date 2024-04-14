class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> umap;
        set<int> res;
        for(int i=0;i<arr.size();i++){
            umap[arr[i]]++;
        }
        for(auto i = umap.begin();i!=umap.end();i++){
            res.insert(i->second);
        }
        return res.size() == umap.size() ? true : false;
    }
};