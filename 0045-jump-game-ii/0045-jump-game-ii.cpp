class Solution {
public:
    int jump(vector<int>& arr) {
         int n = arr.size();
        
        int maxreach = arr[0] ,  step = arr[0] , jump = 1;
        for(int i = 1 ; i < n ; i++){
            if(i == n-1)return jump;
            maxreach = max(maxreach , arr[i] + i);
            step--;
            if(step == 0){
                jump++;
               
                step = maxreach - i;
            }
        }
        return 0;
    }
};