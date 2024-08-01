class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return 0;
        }
        map<int,int> mp;
        for(int i = 0; i < intervals.size(); i++){
            mp[intervals[i][0]]++;
            mp[intervals[i][1]]--;
        }
        int count = 0, maxCount = 0;

        for(auto& m: mp){
            count += m.second;
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};