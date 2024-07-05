class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i=0;i<matrix.size()-1;i++){
            for(int j=i +1 ; j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        int left = 0, right = matrix.size()-1;
        for(int i=0;i<matrix.size();i++){
            int left = 0, right = matrix.size()-1;
            while(left < right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
            
        }
    }
};