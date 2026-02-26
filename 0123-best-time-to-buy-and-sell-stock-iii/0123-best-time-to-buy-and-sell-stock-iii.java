class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if( n < 2)return 0;
        int[] l = new int[n];
        int[] r = new int[n]; 
        int minprice = prices[0];
        for(int i = 1 ; i < n ; i++){
            minprice = Math.min(minprice , prices[i]);
            l[i] = Math.max(l[i-1] , prices[i] - minprice);

        }
        int maxprice = prices[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            maxprice = Math.max(maxprice , prices[i]);
            r[i] = Math.max(r[i+1] ,  maxprice - prices[i] );

        }
        int ans = Integer.MIN_VALUE;
        for(int i = 0 ;i < n ; i++){
            ans = Math.max(ans , l[i] + r[i]);
        }
        return ans;
    }
}