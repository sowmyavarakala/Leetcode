class Solution {
public:
    bool dfs(vector<vector<int>>& adj_list, int course, vector<int>& state, stack<int>& order){
        if(state[course] == 1) return true;
        if(state[course] == 2) return false;

        state[course] = 1;
        for(auto neigh: adj_list[course]){
            if(dfs(adj_list, neigh, state, order)){
                return true;
            }
        }
        state[course] = 2;
        order.push(course);
        return false;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool hasCycle = false;
        vector<vector<int>> adj_list(numCourses);
        vector<int> state(numCourses, 0);
        stack<int> order;

        for(auto& p : prerequisites){
            adj_list[p[1]].push_back(p[0]);
        }

        for(int course = 0; course < numCourses; course++){
            if(state[course] == 0 && dfs(adj_list, course, state, order)){
                hasCycle = true;
                break;
            }
        }
        if(hasCycle) return {};
        vector<int> result;
        while(!order.empty()){
            result.push_back(order.top());
            order.pop();
        }
        return result;
    }
};