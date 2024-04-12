class Solution {
public:
	int maxOperations(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int i = 0 ; int j = arr.size()-1;
        int op =0;
        while(i<j)
        {
            if(arr[i]+arr[j] == k)
            {
                i++;j--;
                op ++;
            }
            else if(arr[i]+arr[j] < k)
            {
                i++;
            }
            else if(arr[i]+arr[j] > k)
            {
                j--;
            }
        }
        return op;
    }
};