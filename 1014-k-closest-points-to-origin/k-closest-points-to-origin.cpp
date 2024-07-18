class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> q;
        vector<vector<int>> result;

        for(auto& point: points){
            int x = point[0];
            int y = point[1];
            q.push({x * x + y * y, x, y});
            if(q.size() > k){
                q.pop();
            }
        }
        for(int i = 0; i < k; i++){
            vector<int> p = q.top();
            q.pop();
            result.push_back({p[1],p[2]});
        }
        return result;
    }
};