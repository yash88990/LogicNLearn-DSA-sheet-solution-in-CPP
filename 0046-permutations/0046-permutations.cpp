#include <algorithm>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;

        // Step 1: sort to start from smallest permutation
        sort(nums.begin(), nums.end());

        // Step 2: keep generating permutations
        do {
            ans.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));

        return ans;
    }
};