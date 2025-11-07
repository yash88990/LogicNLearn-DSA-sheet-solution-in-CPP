class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() , l = 0  , r = 0 , m = 0;
        unordered_set<char>seen;
        while( r < n){
            if(seen.find(s[r]) == seen.end()){
                seen.insert(s[r]);
                m = max(m , r - l + 1);
                r++;
            }else{
                seen.erase(s[l]);
                l++;
            }
        }
        return m;
    }
};