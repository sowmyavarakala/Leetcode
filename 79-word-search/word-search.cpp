class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string word, int index, bool& isTrue){
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size()){
            return;
        }
        if(visited[i][j] == true) return;
        if(board[i][j] == word[index]){
            if(index == word.length()-1){
                isTrue = true;
                return;
            }
            visited[i][j] = true;
            dfs(board, visited, i-1, j, word, index+1, isTrue);
            dfs(board, visited, i+1, j, word, index+1, isTrue);
            dfs(board, visited, i, j+1, word, index+1, isTrue);
            dfs(board, visited, i, j-1, word, index+1, isTrue);
            visited[i][j] = false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool isTrue = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                isTrue = false;
                dfs(board, visited, i, j, word, 0, isTrue);
                if(isTrue) return true;
            }
        }
        return false;
    }
};