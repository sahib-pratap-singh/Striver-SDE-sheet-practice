//A Naive Solution is to generate all possible quadruples and compare the sum of every quadruple with X.
//Time complexity: O(N^4)
//Space complexity" O(1)



//Using sort and Two pointer
//Time complexity: O(N^3)
//Space complexity" O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(nums[i]+nums[i+1]>target-nums[i+2]-nums[i+3]) break;
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(nums[i]+nums[j]>target-nums[j+1]-nums[j+2]) break;
                if(j>i+1 and nums[j]==nums[j-1]){
                    continue;
                }
                int s=j+1;
                int e=n-1;
                while(s<e){
                    long long sum = nums[j]+nums[i]+nums[s]+nums[e];
                    if((sum)==target){
                        ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                        while(s<e and nums[s]==nums[s+1]) s++;
                        while(e>0 and nums[e]==nums[e-1]) e--;
                        s++;
                        e--;
                    }
                    else if(sum<target){
                        s++;
                    }
                    else{
                        e--;
                    }
                }
            }
        }
        return ans;
    }
};

//Above approach can be done with hashing 
//Time complexity: O(N^3)
//Space complexity" O(N)

