//Using backtracking
//Time complexity: O(n*2^n)
//Space complexity: O(N)

class Solution {
public:
    void create(int s, int n, int k, vector<vector<int>>& result, vector<int> &cur){
        if(cur.size()==k){
            result.push_back(cur);
            return;
        }
        else{
            for(int i=s;i<=n;i++){
                cur.push_back(i);
                create(i+1,n,k,result,cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> cur;
        create(1,n,k,result, cur);
        return result;
    }
};