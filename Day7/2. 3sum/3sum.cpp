//Brute force
//Using three loops
//Time complexity: O(N^3)
//Space complexity: O(1)


//Using hashmap
//Time complexity: O(N^2)
//Space complexity: O(N)


//Using sorting and two pointer approach
//Time complexity: O(N^2)
//Space complexity: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            int s=i+1;
            int e=n-1;
            while(s<e){
                if(nums[i]+nums[s]+nums[e]==0){
                    ans.push_back({nums[i],nums[s],nums[e]});
                    while(s<e and nums[s]==nums[s+1]){
                        s++;
                    }
                    s++;
                    while(e>0 and nums[e]==nums[e-1]){
                        e--;
                    }
                    e--;
                }
                else if(nums[i]+nums[s]+nums[e]<0){
                    s++;
                }
                else{
                    e--;
                }
            }
        }
        return ans;
    }
};