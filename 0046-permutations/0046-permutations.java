class Solution {
    public void solve(int[] nums , List<List<Integer>> ans , int index){

        //base case
        if(index >= nums.length){
            List<Integer> temp = new ArrayList<>();
            for(int num : nums)temp.add(num);
            ans.add(temp);

            return;
        }
        for(int i = index ; i < nums.length ; i++){
           swap(nums , i , index);
           solve(nums , ans , index + 1 );
            swap(nums , i , index);
        }
    }
    private void swap(int[] arr , int start , int end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        solve(nums , ans , 0);
        return ans;
    }
}