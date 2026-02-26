class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = nums[0];
        int min_prod = nums[0];
        int result = max_prod;
        for(int i = 1 ; i < nums.size() ; i++){
            int temp_max = max_prod;
            int temp_min = min_prod;
            max_prod = max(nums[i] , max(temp_max * nums[i] , temp_min * nums[i]));
            min_prod = min(nums[i] , min(temp_max * nums[i] , temp_min * nums[i]));
            result = max(max_prod , result);

        }
        return result;
    }
};