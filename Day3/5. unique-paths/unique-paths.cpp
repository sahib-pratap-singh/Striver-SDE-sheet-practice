//Recursion
// Time Complexity : O(2m+n), where m and n are the given input dimensions of the grid
// Space Complexity : O(m+n), required by implicit recursive stack

class Solution {
public:
    int count=0;
    void dfs(vector<vector<int>>& grid,int i,int j, int m,int n){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1){
            return;
        }
        if(i==m and j==n){
            count++;
            return;
        }
        grid[i][j]=-1;
        //dfs(grid,i-1,j,m,n);
        dfs(grid,i+1,j,m,n);
        //dfs(grid,i,j-1,m,n);
        dfs(grid,i,j+1,m,n);
        grid[i][j]=0;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        dfs(grid,0,0,m-1,n-1);
        return count;
    }
};

//Memorization
// Time Complexity : O(m*n), the answer to each of cell is calculated only once and memoized. There are m*n cells in total and thus this process takes O(m*n) time.
// Space Complexity : O(m*n), required to maintain dp.

class Solution {
public:
    int count=0;
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& memo,int i,int j, int m,int n){
        //Base condition
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1){
            return 0;
        }
        //Reached the final place increment counter
        if(i==m and j==n){
            count++;
            return 1;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        grid[i][j]=-1;
        //Bottom
        int bottom= dfs(grid,memo,i+1,j,m,n);
        //Right
        int right= dfs(grid,memo,i,j+1,m,n);
        //Backtracking
        grid[i][j]=0;
        return memo[i][j]=bottom+right;
    }
    int uniquePaths(int m, int n) {
        //create and initialize grid with 0
        vector<vector<int>> grid(m,vector<int>(n,0));
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return dfs(grid,memo,0,0,m-1,n-1);
        return count;
    }
};

//Dynamic programming
// Time Complexity : O(m*n), we are computing dp values for each of the m*n cells from the previous cells value. Thus, the total number of iterations performed is requires a time of O(m*n).
// Space Complexity : O(m*n), required to maintain the dp matrix

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};