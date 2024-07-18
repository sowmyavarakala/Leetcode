class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int intervals = 0;
        unordered_map<char,int> mp;
        priority_queue<int> q;
        for(auto c: tasks){
            mp[c]++;
        }

        for(auto c: mp){
            q.push(c.second);
        }

        while(!q.empty()){
            vector<int> temp;
            int i = 0;

            while(i <= n){
                if(!q.empty()){
                    int count = q.top();
                    q.pop();
                    if(count > 1)
                        {
                            temp.push_back(count-1);
                            }
                    
                }
                intervals++;
                if(q.empty() && temp.empty()) break;
                i++;
            }
            for(int t: temp){
                q.push(t);
            }
        }
        return intervals;
        
    }
};