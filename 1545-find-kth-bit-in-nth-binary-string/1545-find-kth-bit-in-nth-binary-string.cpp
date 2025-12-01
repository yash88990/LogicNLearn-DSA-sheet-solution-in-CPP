class Solution {
public:
     string invert( string& s) {
        string ans = "";
        for (char& c : s) {
            if(c == '0')ans += "1";
            else ans += "0";
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
    char solve(int n, int k) {
        string s = "0"; 
        for (int i = 2; i <= n; i++) {
            s += "1" + invert(s);
        }
        return s[k-1];
    }

    char findKthBit(int n, int k) {
        char ans = solve(n , k);
        return ans;
        
    }
};