class Solution {
private: 
    bool isSafePlace(int n, vector<string>& nQueens, int row, int col){
        
        int dulcol = col;
        int dulrow = row;
        while(col >= 0 && row >= 0){
            if(nQueens[row][col] == 'Q'){
                return false;
            }
            col--;
            row--;
        }
        col = dulcol;
        row = dulrow;
        while(col >= 0){
            if(nQueens[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        col = dulcol;
        row = dulrow;
        while(row < n && col >= 0){
            if(nQueens[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }

        return true;
    }
    void solveNQueens(int n, vector<vector<string>>& output, vector<string>& nQueens, int col){
        if(col == n){
            output.push_back(nQueens);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafePlace(n, nQueens, row, col)){
                nQueens[row][col] = 'Q';
                solveNQueens(n, output, nQueens, col+1);
                nQueens[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> nQueens(n , string(n, '.')); 
        // for ( string i: nQueens){
        //     cout << i << endl;
        // }
        solveNQueens(n, output, nQueens, 0);
        return output;
    }
};