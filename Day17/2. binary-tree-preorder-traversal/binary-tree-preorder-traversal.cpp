//Approach 1

//Recursive method
//Time complexity: O(N)
//Space complexity: O(N)


class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

//Iterative method using stack
//Time complexity: O(N)
//Space complexity: O(N)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* cur=s.top();
            s.pop();
            ans.push_back(cur->val);
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }
        return ans;
    }
};

//Morris traversal
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    nodes.push_back(root -> val);
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }
};