//Sorting
//Time complexity:O(Nlog(N))
//Space complexity:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto it=nums.begin();it!=nums.end()-1;++it){
            if(*it == *(it+1)){
                return *it;
            }
        }
        return -1;
    }
};

//Negating
//Time complexity:O(N+N)
//Space complexity:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1] >0){
                nums[0]=abs(nums[i]);
                return nums[0];
            }
        }
        return nums[0];
    }
};

//Array as HashMap 
//Time complexity:O(N)
//Space complexity:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0]!=nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};