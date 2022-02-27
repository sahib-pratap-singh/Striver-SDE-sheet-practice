//Brute force approach is to iterate the matrix
//Time complexity:O(n*n)
//Space complexity:O(1)

//Another approach is to compare the target element with the last element of the matrix till last element of the matrix become larger than it.
//Time complexity:O(n+n)
//Space complexity:O(1)

//Binary search
//Time complexity:O(log(n))
//Space complexity:O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int b) {
        int r=grid.size();
        int c=grid[0].size();
        int s=0;
        int e=r*c-1;;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(grid[mid/c][mid%c]==b){
                return 1;
            }
            if(grid[mid/c][mid%c]>b){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return 0;
    }
};