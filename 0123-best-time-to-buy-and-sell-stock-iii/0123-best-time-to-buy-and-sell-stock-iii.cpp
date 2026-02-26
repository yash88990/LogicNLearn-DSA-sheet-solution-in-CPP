class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if( n < 2)return 0;
        vector<int> l( n ) , r(n); 
        int minprice = prices[0];
        for(int i = 1 ; i < n ; i++){
            minprice = min(minprice , prices[i]);
            l[i] = max(l[i-1] , prices[i] - minprice);

        }
        int maxprice = prices[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            maxprice = max(maxprice , prices[i]);
            r[i] = max(r[i+1] ,  maxprice - prices[i] );

        }
        int ans = INT_MIN;
        for(int i = 0 ;i < n ; i++){
            ans = max(ans , l[i] + r[i]);
        }
        return ans;
    }
};