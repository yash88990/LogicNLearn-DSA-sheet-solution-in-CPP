class Solution {
    public int maxProduct(int[] nums) {
        int max_prod = nums[0];
        int min_prod = nums[0];
        int result = max_prod;
        for(int i = 1 ; i < nums.length ; i++){
            int temp_max = max_prod;
            int temp_min = min_prod;
            max_prod = Math.max(nums[i] , Math.max(temp_max * nums[i] , temp_min * nums[i]));
            min_prod = Math.min(nums[i] , Math.min(temp_max * nums[i] , temp_min * nums[i]));
            result = Math.max(max_prod , result);

        }
        return result;
    }
}