class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m+n, 0);
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] = res[i + j + 1] % 10;
            }
        }
        int i = 0;
        while(i < res.size() && res[i] == 0) ++i;
        string result = "";
        while(i < res.size()) result.push_back(res[i++] + '0');
        return result;
    }
};