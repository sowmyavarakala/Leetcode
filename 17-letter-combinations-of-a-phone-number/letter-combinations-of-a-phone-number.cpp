class Solution {
public:
    vector<string> result;
    void helper(string digits, string comb, int index, const unordered_map<char, string>& digitChars){
        if(index == digits.size()){
            result.push_back(comb);
            return;
        }
        char digit = digits[index];
        string letters = digitChars.at(digit);

        for(char letter: letters){
            comb.push_back(letter);
            helper(digits, comb, index + 1, digitChars);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> dightChars = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        string comb;
        helper(digits, comb, 0, dightChars);
        return result;
    }
};