#include<bits/stdc++.h>

//Time complexity: O(N^2)
//Space complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=nums[0];
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                result=max(result,sum);
            }
        }
        return result;
    }
};

//Time complexity: O(N)
//Space complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minsf=0;
        int maxsf=INT_MIN;
        for(int i=0;i<nums.size();i++){
            minsf+=nums[i];
            maxsf=max(minsf,maxsf);
            if(minsf<0){
                minsf=0;
            }
        }
        return maxsf;
    }
};