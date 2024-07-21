class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);

        for(int i = 0; i < n; i++){
            cars[i] = {position[i], static_cast<double>(target-position[i])/ speed[i]};
        }
        sort(cars.rbegin(), cars.rend());
        stack<double> st;

        for(auto& car: cars){
            double time = car.second;
            if(st.empty() || st.top() < time)
                st.push(time);
        }
        return st.size();
    }
};