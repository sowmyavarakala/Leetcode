class Solution {
public:
    int DFS(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i >= grid.size() || j<0 || j >= grid[0].size())
            return 0;
        if(grid[i][j] == 2 || grid[i][j] == 0)
            return 0;
        grid[i][j] =2;
        int area = 1;
        area += DFS(i+1,j,grid);
        area += DFS(i,j-1,grid);
        area += DFS(i-1,j,grid);
        area += DFS(i,j+1,grid);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        for(int i = 0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1)
                {
                    area = max(area, DFS(i,j,grid));
                }
            }
        }
        return area;
    }
};