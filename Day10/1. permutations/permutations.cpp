//Recursion
//Time complexity: O(N*2^N)
//Space complexity: O(N)
class Solution {
public:
    void create(int s,vector<int> nums, vector<vector<int>>& result,vector<int>& chosen,vector<int>& cur){
        if(nums.size()==cur.size()){
            result.push_back(cur);
        }
        else{
            for(int i=0;i<nums.size();i++){
                if(chosen[i]){
                    continue;
                }
                chosen[i]=1;
                cur.push_back(nums[i]);
                create(i+1,nums,result,chosen,cur);
                cur.pop_back();
                chosen[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<int> chosen(nums.size(),0);
        create(0,nums,result,chosen,cur);
        return result;
    }
};