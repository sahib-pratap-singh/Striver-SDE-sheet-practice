// one of the brute force approach is to iterate using two loops and count each element
//Time complexity:O(N*N)
//Space complexity:O(1)

//Another approach is to use sorting and return nums[n/2+1]
//Time complexity:O(NLog(N))
//Space complexity:O(1)

// using unordered map
//Time complexity:O(N)
//Space complexity:O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int n=nums.size();
        for(auto x:nums){
            count[x]++;
            if(count[x]>n/2){
                return x;
            }
        }
        return -1;
    }
};

//Boyer-Moore Voting Algorithm
//Time complexity:O(N)
//Space complexity:O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int present=0;
        for(auto num:nums){
            if(count==0){
                present=num;
            }
            count+=(present==num)?1:-1;
        }
        return present;
    }
};