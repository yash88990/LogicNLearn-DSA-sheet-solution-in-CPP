class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int,int> freq;
        for(int num : nums)freq[num]++;
        for(auto entry : freq){
            if(entry.second == n)return entry.first;
        }
        return -1;
    }
};