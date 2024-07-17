class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        vector<int> indegree(numCourses, 0);
        stack<int> order;

        for(auto& p : prerequisites){
            adj_list[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        vector<int> result;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                order.push(i);
            }
        }
        while(!order.empty()){
            int course = order.top();
            order.pop();
            result.push_back(course);

            for(int neigh: adj_list[course]){
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    order.push(neigh);
                }
            }
        }
        if(result.size() != numCourses) return {};
        
        
        return result;
    }
};