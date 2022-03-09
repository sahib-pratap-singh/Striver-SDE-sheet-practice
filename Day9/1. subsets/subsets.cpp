//Using backtracking
//Time complexity: n*2^n
//Space complexity: O(N)

class Solution {
public:
    void solve(int s, int n, vector<int>& nums, vector<int> &ans, vector<vector<int>>& result){
        result.push_back(ans);
        for(int i=s;i<n;i++){
            ans.push_back(nums[i]);
            solve(i+1,n,nums,ans,result);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        solve(0,nums.size(),nums,ans,result);
        return result;
    }
};

//Cascading
//Time complexity: n*2^n
//Space complexity: n*2^n
class Solution {
  public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> output = new ArrayList();
    output.add(new ArrayList<Integer>());

    for (int num : nums) {
      List<List<Integer>> newSubsets = new ArrayList();
      for (List<Integer> curr : output) {
        newSubsets.add(new ArrayList<Integer>(curr){{add(num);}});
      }
      for (List<Integer> curr : newSubsets) {
        output.add(curr);
      }
    }
    return output;
  }
}