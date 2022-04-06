class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0,count2=0,candidate1=0,candidate2=0;
        for(auto n:nums){
            if(n==candidate1){
                count1++;
            }
            else if(n==candidate2){
                count2++;
            }
            else if(count1==0){
                candidate1=n;
                count1++;
            }
            else if(count2==0){
                candidate2=n;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        int it1=count(nums.begin(),nums.end(),candidate1);
        int it2=count(nums.begin(),nums.end(),candidate2);
        cout<<it1<<" "<<it2;
        int cmp=n/3;
        if(it1>cmp and it2>cmp and candidate1!=candidate2){
            return {candidate1,candidate2};
        }
        else{
            if(it1>cmp){
                return {candidate1};
            }
            else if(it2>cmp){
                return {candidate2};
            }
        }
        return {};
    }
};