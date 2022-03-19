// Recursive 
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    int ans=0;
    void solve(TreeNode* root, int d){
        if(root==NULL){
            return;
        }
        ans=max(ans,d);
        solve(root->left,d+1);
        solve(root->right,d+1);
    }
    int maxDepth(TreeNode* root) {
        solve(root,1);
        return ans;
    }
};

//Another method to solve this problem is to do Level Order Traversal. 
//Time complexity: O(N)
//Space complexity: O(N)