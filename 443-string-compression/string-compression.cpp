class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        while(j < chars.size()){
            int count = 0;
            char curr = chars[j];
            while(j < chars.size() && chars[j] == curr){
                count++;
                j++;
            }
            chars[i++] = curr;
            if(count > 1){
                for (char c : to_string(count)){
                    chars[i++] = c;
                }

            }
        }
        return i;
    }
};