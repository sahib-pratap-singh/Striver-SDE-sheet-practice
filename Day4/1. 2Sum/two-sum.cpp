//Time complexity: O(N*N)
//Space complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};

//Hashing
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                return {mp[nums[i]],i};
            }
            mp[target-nums[i]]=i;
        }
        return v;
    }
};

//Sorting and Two pointer approach
//Time complexity: O(Nlog(N))
//Space complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if((nums[i]+nums[j])==target){
                return {i,j};
            }
            if((nums[i]+nums[j])<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};