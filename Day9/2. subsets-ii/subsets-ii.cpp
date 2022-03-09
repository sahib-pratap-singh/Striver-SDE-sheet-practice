//Using backtracking
//Time complexity: O(n*2^n)
//Space complexity: O(N)
class Solution {
public:
    void findsubset(int start, int n, vector<int> &subset,vector<int> &nums, vector<vector<int>> &result){
        result.push_back(subset);
        for(int i=start;i<n;i++){
            if(i>start and nums[i]==nums[i-1]){
                continue;
            }
            subset.push_back(nums[i]);
            findsubset(i+1,n,subset,nums,result);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        int n=nums.size();
        findsubset(0,n,subset,nums,result);
        return result;
    }
};