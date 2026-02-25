class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int maxreach = 0 , jump = 0 , currentend = 0 ;
        for(int i = 0 ; i < n-1 ; i++){
            maxreach = Math.max(maxreach , i + nums[i]);
            if(i == currentend){
                jump++;
                currentend = maxreach;
                if(currentend >= n-1)break;
            }
        } 
        return jump;
    }
}