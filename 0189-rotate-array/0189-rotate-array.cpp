class Solution {
public:
    vector<int> reverse_array(vector<int>&nums , int start , int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
        return nums;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        //step 1 :- reverse whole array
        reverse_array(nums , 0 , n  -1);
        //step 2 :- reverse index 0 to k-1
        reverse_array(nums , 0 , k -1);
        //step 3 :- reverse index k to n
        reverse_array(nums , k , n -1);

    }
};