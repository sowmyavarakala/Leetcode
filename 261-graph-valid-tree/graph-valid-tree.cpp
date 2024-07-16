class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj_list(n);
        for(auto e: edges){
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        if(hasCycle(adj_list, 0, -1, visited)){
            return false;
        }
        for(bool v: visited){
            if(!v) return false;
        }
        return true;
    }
        bool hasCycle(unordered_map<int, vector<int>>& adj_list, int kid, int parent, vector<bool>& visited) {
        if(visited[kid]) return true;
        visited[kid] = true;
        for(auto neigh: adj_list[kid]){
            if(neigh != parent && hasCycle(adj_list, neigh, kid, visited)){
                return true;
            }
        }
        return false;
    }
};