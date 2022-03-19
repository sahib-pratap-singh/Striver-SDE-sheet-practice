// Recursive 
//Time complexity: O(N)
//Space complexity: O(N)

class Pair{
    public:
    int height;
    int diameter;
};
class Solution {
public:
    Pair diam(TreeNode* root){
        Pair p;
        if(root==NULL){
            p.height=0;
            p.diameter=0;
            return p;
        }
        Pair left=diam(root->left);
        Pair right=diam(root->right);
        p.height=1+max(left.height,right.height);
        p.diameter=max((left.height+right.height),max(left.diameter,right.diameter));
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        Pair p=diam(root);
        return p.diameter;
    }
};

//Recursive
//Time complexity: O(N^2)
//Space complexity: O(N)
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return max((height(root->left)+height(root->right)),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};

//Recursive
//Time complexity: O(N)
//Space complexity: O(1)
int height(Node* root, int& ans)
{
    if (root == NULL)
        return 0;
 
    int left_height = height(root->left, ans);
 
    int right_height = height(root->right, ans);
 
    // update the answer, because diameter of a
    // tree is nothing but maximum value of
    // (left_height + right_height + 1) for each node
    ans = max(ans, 1 + left_height + right_height);
 
    return 1 + max(left_height, right_height);
}