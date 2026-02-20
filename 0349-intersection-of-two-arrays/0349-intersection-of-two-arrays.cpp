class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //step 1 :_ sort both array
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        vector<int>ans;
        //step 2 : set pointer
        int i = 0 , j = 0;
        while(i < nums1.size() && j < nums2.size()){
            //case1  
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;

            }else if(nums1[i] > nums2[j]) j++;
            else i++;
        }
        //step 3 :- handle dublicate
        vector<int>result;
        if(!ans.empty())result.push_back(ans[0]);
        for(int i = 1 ;i < ans.size() ; i++){
            if(ans[i] == ans[i-1])continue;
            else result.push_back(ans[i]);
        }
        return result;
    }
};