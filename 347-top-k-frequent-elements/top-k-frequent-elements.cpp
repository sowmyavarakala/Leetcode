class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>> p;
        for(auto j = mp.begin();j != mp.end();j++){
            p.push(make_pair(j->second,j->first));
            if(p.size() > mp.size()-k){
                result.push_back(p.top().second);
                p.pop();
            }
        }
        return result;
    }
};