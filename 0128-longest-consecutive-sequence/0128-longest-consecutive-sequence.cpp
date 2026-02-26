class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if( n < 1)return 0;
        sort(arr.begin()  , arr.end());
        int cnt = 1 , maxi = 1 , ele = arr[0];
        for(int i = 1 ; i < n ; i++){
            if(arr[i] == arr[i-1])continue;
            if(arr[i] == ele + 1 )cnt++;
            else{
                maxi = max(maxi , cnt);
                cnt = 1;
            }
            ele = arr[i];
        }
        return max(maxi , cnt);
    }
};