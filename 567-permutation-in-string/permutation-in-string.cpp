class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> count1(26,0), count2(26,0);
        int i;
        for(i = 0; i < s1.size(); i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        if(count1 == count2) return true;
        int start = 0, end = i;
        while(end < s2.size()){
            --count2[s2[start]-'a'];
            ++count2[s2[end]-'a'];
            if(count1 == count2) return true;
            start++;
            end++;
        }
        return false;
    }
};