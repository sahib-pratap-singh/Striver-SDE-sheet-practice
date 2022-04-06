//1st approach and really easy
//Take the transpose of the matrix and reverse every row
class Solution {
public:
    void swap(int &a, int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        //No of rows
        int rows=matrix.size();
        //No of columns
        int cols=matrix[0].size();
        //Transpose of the matrix
        for(int i=0;i<rows;i++){
            for(int j=i;j<cols;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<rows;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//2nd approach and efficient, only three swaps :)
//Literally today i understand this

//Time complexity: O(rows/2 + cols/2) -> O(N)
//Space complexity: O(1)
class Solution {
public:
    //swapping the two numbers
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        //as it's 2d matrix so rows==cols
        int n=matrix.size();
        //if n is odd so we will traverse n/2 + 1 rows
        //if n is even we will traverse n/2
        //for cols we will traverse n/2
        for(int i=0;i<n/2+n%2;i++){
            for(int j=0;j<n/2;j++){
                swap(matrix[n-j-1][i],matrix[n-i-1][n-j-1]);
                swap(matrix[n-i-1][n-j-1],matrix[j][n-i-1]);
                swap(matrix[i][j],matrix[j][n-i-1]);
            }
        }
    }
};