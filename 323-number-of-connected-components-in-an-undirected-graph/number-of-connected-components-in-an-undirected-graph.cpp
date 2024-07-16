class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj_list(n);
        for(auto e: edges){
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        int label = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            label++;
            dfs(adj_list, visited, i);
        }
        return label;
    }

    void dfs(unordered_map<int, vector<int>>& adj_list, vector<bool>& visited, int node){
        if(visited[node]) return;
        visited[node] = true;
        for(auto neigh: adj_list[node]){
            if(!visited[neigh]) dfs(adj_list, visited, neigh);
        }

    }
};