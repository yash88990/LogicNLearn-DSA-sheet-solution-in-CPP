class Solution {
    public int longestConsecutive(int[] nums) {
    //  if(nums.isEmpty())return 0;
        Arrays.sort(nums);
        int ans = 1 , count = 1 , n = nums.length;
        if(n < 1)return 0;
        int start = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(nums[i-1] == nums[i])continue;
            if(start + 1 == nums[i])count++;
            else {
                ans = Math.max(ans , count);
                count = 1 ;
            }
            start = nums[i];


        }
        return Math.max(ans , count);       
    }
}