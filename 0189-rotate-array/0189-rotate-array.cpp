class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        //step 1 :- reverse whole array
        reverse(nums.begin() , nums.end());
        //step 2 :- reverse index 0 to k-1
        reverse(nums.begin() , nums.begin() + k);
        //step 3 :- reverse index k to n
        reverse(nums.begin() + k , nums.end());

    }
};