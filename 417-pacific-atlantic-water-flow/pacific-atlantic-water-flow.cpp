class Solution {
public:

    void dfs(vector<vector<bool>>& visited, vector<vector<int>>& heights, int i, int j){
        int m = heights.size();
        int n = heights[0].size();
        visited[i][j] = true;

        if(i-1 >= 0 && visited[i-1][j] != true && heights[i-1][j] >= heights[i][j]){
            dfs(visited, heights, i-1, j);
        }if(i+1 < m && visited[i+1][j] != true && heights[i+1][j] >= heights[i][j]){
            dfs(visited, heights, i+1, j);
        }if(j-1 >= 0 && visited[i][j-1] != true && heights[i][j-1] >= heights[i][j]){
            dfs(visited, heights, i, j-1);
        }if(j+1 < n && visited[i][j+1] != true && heights[i][j+1] >= heights[i][j]){
            dfs(visited, heights, i, j+1);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            dfs(pacific, heights, i, 0);
            dfs(atlantic, heights, i, n-1);
        }

        for(int j = 0; j < n; j++){
            dfs(pacific, heights, 0, j);
            dfs(atlantic, heights, m-1, j);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};