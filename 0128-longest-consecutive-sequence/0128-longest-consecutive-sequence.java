class Solution {
    public int longestConsecutive(int[] arr) {
        int n = arr.length;
        if( n < 1)return 0;
        Arrays.sort(arr);
        int cnt = 1 , maxi = 1 , ele = arr[0];
        for(int i = 1 ; i < n ; i++){
            if(arr[i] == arr[i-1])continue;
            if(arr[i] == ele + 1 )cnt++;
            else{
                maxi = Math.max(maxi , cnt);
                cnt = 1;
            }
            ele = arr[i];
        }
        return Math.max(maxi , cnt);
    }
}