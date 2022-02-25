//1st approach, storing indexes in 2 sets
//Time complexity : O(rows * cols)
//Space complexity: O(log(n))
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //no of rows
        int rows=matrix.size();
        //no of columns
        int cols=matrix[0].size();
        
        //Set 1
        set<int> set1;
        //Set 2
        set<int> set2;
        //finding the index of o elements.
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    set1.insert(i);
                    set2.insert(j);
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(set1.count(i) || set2.count(j)){
                    matrix[i][j]=0;
                }
            }
        }
    }
};


//2nd approach and the efficient one
//We will create 1st row and 1st column as flag.
// Time complexity: O(rows*cols)
//Space complexity: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //no of rows
        int rows=matrix.size();
        //no of cols
        int cols=matrix[0].size();
        //Check 1st row contains 0 or not
        bool firstrowcontainszero=false;
        for(int i=0;i<cols;i++){
            if(matrix[0][i]==0){
                firstrowcontainszero=true;
            }
        }
        //check first col contains 0 or not
        bool firstcolcontainszero=false;
        for(int i=0;i<rows;i++){
            if(matrix[i][0]==0){
                firstcolcontainszero=true;
            }
        }
        //Now creating 1st row and 1st col as a flag.
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //inserting 0 in rows and cols acoording to flag
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        //if first row contain 0 then mark the row 0
        if(firstrowcontainszero){
            for(int i=0;i<cols;i++){
                matrix[0][i]=0;
            }
        }
        //if first col contain 0 then mark the row 0
        if(firstcolcontainszero){
            for(int i=0;i<rows;i++){
                matrix[i][0]=0;
            }
        }
    }
};