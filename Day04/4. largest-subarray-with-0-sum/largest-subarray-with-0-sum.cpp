//Naive approach is to solve with two nested loops
//Time complexity: O(n*n)
//Space complexity: O(1)

//Hashing
//Time complexity: O(n)
//Space complexity: O(n)

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> mp;
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                cnt=i+1;
            }
            if(mp.count(sum)){
                cnt=max(cnt,i-mp[sum]);
            }
            //cnt=max(cnt,i-mp[sum]);
            else{
                mp[sum]=i;
            }
        }
        return cnt;
    }
};