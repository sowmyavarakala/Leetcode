class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list and compute in-degrees
        vector<vector<int>> adj_list(numCourses);
        vector<int> in_degree(numCourses, 0);

        for (const auto& p : prerequisites) {
            adj_list[p[1]].push_back(p[0]);
            in_degree[p[0]]++;
        }

        // Step 2: Add courses with in-degree 0 to the queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Process the courses
        int processed_courses = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            processed_courses++;

            // Reduce the in-degree of neighbors
            for (int neighbor : adj_list[course]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Check if all courses have been processed
        return processed_courses == numCourses;
    }
};
