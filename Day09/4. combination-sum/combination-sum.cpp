//Using backtracking
//Time complexity: O(n*2^n)
//Space complexity: O(N)

class Solution {
public:
    void solve(int s, int &sum,vector<int>& cand, vector<int> &ans,vector<vector<int>> &result, int t){
        if(sum>=t){
            if(sum==t){
                result.push_back(ans);
            }
            return;
        }
        for(int i=s;i<cand.size();i++){
            sum+=cand[i];
            ans.push_back(cand[i]);
            solve(i,sum,cand,ans,result,t);
            ans.pop_back();
            sum-=cand[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
        vector<int> ans;
        vector<vector<int>> result;
        int sum=0;
        solve(0,sum,cand,ans,result,t);
        return result;
    }
};