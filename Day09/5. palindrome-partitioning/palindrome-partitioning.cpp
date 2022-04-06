class Solution {
public:
    bool palindreome(string s, int start, int end){
        while(start<end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void palipart(int ind,int n, string s, vector<string> &ds, vector<vector<string>> &ans){
        if(ind == n){
            ans.push_back(ds);
        }
        
        for(int i=ind;i<n;i++){
            if(palindreome(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                palipart(i+1,n,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        palipart(0,s.length(),s,ds,ans);
        return ans;
    }
};