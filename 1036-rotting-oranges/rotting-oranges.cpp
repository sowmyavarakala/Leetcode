class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> rotten;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int freshCount = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    rotten.push({i, j});
                }
                if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }
        int count = 0;
        while(!rotten.empty() && freshCount > 0){
            count++;
            int q_size = rotten.size();
            for(int i = 0; i < q_size; i++){
                int r = rotten.front().first;
                int c = rotten.front().second;
                rotten.pop();

                for (auto dir: directions){
                    int x = r + dir.first;
                    int y = c + dir.second;
                    if(x >= 0 && y >= 0 && y < col && x <row && grid[x][y] == 1){
                        grid[x][y] = 2;
                        rotten.push({x,y});
                        freshCount--;
                    }
                }
            }
        }
        return freshCount == 0 ? count : -1;
    }
};