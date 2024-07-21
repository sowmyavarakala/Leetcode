class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int colms[9][9] = {0};
        int boxes[3][3][9] = {0};

        for(int r=0;r<board.size();r++){
            for(int c=0;c<board[0].size();c++){
                if(board[r][c] != '.'){
                    int number = board[r][c] - '1';
                    if(rows[r][number]++)
                        return 0;
                    if(colms[c][number]++)
                        return 0;
                    if(boxes[r/3][c/3][number]++)
                        return 0;
                }
            }
        }
        return 1;
    }
};