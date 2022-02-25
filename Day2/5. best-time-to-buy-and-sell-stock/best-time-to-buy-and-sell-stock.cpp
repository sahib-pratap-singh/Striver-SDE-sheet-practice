//Time complexity: O(n*n)
//Space complexity: O(1)
public class Solution {
    public int maxProfit(int prices[]) {
        int maxprofit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }
}

//Time complexity: O(n)
//Space complexity: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int left[n+1];
        int right[n+1];
        int mn=prices[0];
        for(int i=0;i<n;i++){
            if(mn>=prices[i]){
                mn=prices[i];
            }
            left[i]=mn;
        }
        int mx=prices[n-1];
        for(int i=n-1;i>=0;i--){
            if(mx<prices[i]){
                mx=prices[i];
            }
            right[i]=mx;
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            //cout<<left[i]<<" "<<right[i]<<endl;
            ans=max(ans,right[i]-left[i]);
        }
        return ans;
    }
};

//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mx=prices[n-1];
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(mx<prices[i]){
                mx=prices[i];
            }
            ans=max(ans,mx-prices[i]);
        }
        return ans;
    }
};