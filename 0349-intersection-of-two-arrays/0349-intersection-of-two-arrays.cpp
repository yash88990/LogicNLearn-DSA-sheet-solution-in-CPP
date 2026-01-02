class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(nums1.begin() , nums1.end());
        set<int>s2(nums2.begin() , nums2.end());
        vector<int>a (s1.begin() , s1.end());
        vector<int>b(s2.begin() , s2.end());
        int i = 0 , j = 0;
        vector<int>ans;
        while( i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }else if(a[i] > b[j]){
                j++;
            }else{
                i++;
            }
        }
        return ans;
        
    }
};