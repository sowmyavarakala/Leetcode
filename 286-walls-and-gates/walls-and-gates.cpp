class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size();
        int col = rooms[0].size();
        queue<pair<int, int>> gates;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(rooms[i][j] == 0){
                    gates.push({i, j});
                }
            }
        }
        while(!gates.empty()){
            int r = gates.front().first;
            int c = gates.front().second;
            gates.pop();

            for (auto dir: directions){
                int x = r + dir.first;
                int y = c + dir.second;
                if(x < 0 || y < 0 || y >= col || x >= row || rooms[x][y] <= rooms[r][c]+1) continue;
                rooms[x][y] = rooms[r][c] + 1;
                gates.push({x,y}); 
            }
        }
    }
};