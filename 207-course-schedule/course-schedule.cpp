class Solution {
private:
    bool dfs(int course, const vector<vector<int>>& adj_list, vector<int>& state) {
        if (state[course] == 1) return true;  
        if (state[course] == 2) return false; 

        state[course] = 1; 
        for (int neighbor : adj_list[course]) {
            if(dfs(neighbor, adj_list, state)) return true;
        }
        state[course] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        vector<int> state(numCourses, 0);

        // Build the adjacency list
        for (auto& p : prerequisites) {
            adj_list[p[1]].push_back(p[0]);
        }

        // Check for cycles in all courses
        for (int course = 0; course < numCourses; ++course) {
            if (state[course] == 0 && dfs(course, adj_list, state)) {
                return false;
            }
        }
        
        return true;
        
    }
};