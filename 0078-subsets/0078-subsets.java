class Solution {
    public void solve(int[] nums , List<Integer>output , List<List<Integer>> ans , int index){
        if(index >= nums.length){
            ans.add(new ArrayList<>(output));
            return;
        }
        //exclude
        solve(nums , output , ans , index + 1 );
        //include
        output.add(nums[index]);
        solve(nums , output , ans  , index + 1);
        output.remove(output.size() - 1);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> output = new ArrayList<>();
        solve(nums , output , ans , 0);
        return ans;
    }
}