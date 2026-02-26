class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int mid = n / 2 ;
        return nums[mid];
    }
}