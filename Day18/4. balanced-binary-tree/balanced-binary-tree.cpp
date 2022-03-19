//Approach 1

//Time complexity: O(N*N)
//Space complexity: O(N)
class Solution {
public:
    //Calculating the height
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        return abs(leftHeight-rightHeight)<2 and isBalanced(root->left) and isBalanced(root->right);
    }
};
//Approach 2
//Efficient solution by taking a pair of height and balanced

//Time complexity: O(N)
//Space complexity: O(N)

class pair1{
    public:
    int height;
    bool balanced;
};
class Solution {
public:
    pair1 checkBalanced(TreeNode* root){
        pair1 p;
        if(root==NULL){
            p.height=0;
            p.balanced=true;
            return p;
        }
        pair1 left=checkBalanced(root->left);
        pair1 right=checkBalanced(root->right);
        
        p.height=1+max(left.height,right.height);
        if(abs(left.height-right.height)<2 and left.balanced and right.balanced){
            p.balanced=true;
        }
        else{
            p.balanced=false;
        }
        return p;
    }
    bool isBalanced(TreeNode* root) {
        return checkBalanced(root).balanced;
    }
};

//Approach 3

//Time complexity: O(N)
//Space complexity: O(N)
class solution {
public:
int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    }
};