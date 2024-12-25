class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> store;
        for(int i=0;i<s.size();i++){
            store[s[i]]++;
            store[t[i]]--;
        }
        for(auto x:store){
            if(x.second>0)
                return false;
        }
        return true;
    }
};