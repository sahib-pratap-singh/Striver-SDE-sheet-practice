//Basic approach is to find all the permutations and return appropriate result
//Time complexity : O(n!)
//Space complexity: O(n)

//Time complexity : O(n)
//Space complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;   
            }
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(j=nums.size()-1;j>i;j--){
                if(nums[j]>nums[i]){
                    break;
                }
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};