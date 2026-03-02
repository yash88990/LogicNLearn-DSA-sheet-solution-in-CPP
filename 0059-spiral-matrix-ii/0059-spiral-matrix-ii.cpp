class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n , vector<int>(n));
        int top = 0 , bottom = n-1 , left = 0 , right = n-1 , index = 1;
        while(top <= bottom && left <= right){
            for(int i = left ; i <= right ; i++){
                ans[top][i] = index++ ;

            }
            top++;
            for(int i = top ; i <= bottom ; i++){
                ans[i][right] = index++;

            }
            right--;
            if(top <= bottom){
                for(int i = right ; i >= left ; i--){
                    ans[bottom][i] = index++;

                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom ; i >= top ; i--){
                    ans[i][left] = index++;

                }
                left++;
            }
        }
        return ans;
    }
};