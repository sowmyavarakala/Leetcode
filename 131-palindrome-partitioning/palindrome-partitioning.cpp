class Solution {
public:
    vector<vector<string>> result;
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void helper(string s, vector<string>& path, int index){
        if(index == s.length()){
            result.push_back(path);
            return;
        }
        for(int i = index; i < s.length(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                helper(s, path, i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        helper(s, path, 0);
        return result;
    }
};