//Approach 1

//Recursive method
//Time complexity: O(N)
//Space complexity: O(N)


class Solution {
public:
    vector<int> v;
    void postorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return v;
    }
};

//Iterative method using stack
//Time complexity: O(N)
//Space complexity: O(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        vector<int> v;
        if(root==NULL){
            return v;
        }
        while(!s.empty()){
            TreeNode* cur=s.top();
            s.pop();
            v.push_back(cur->val);
            if(cur->left){
                s.push(cur->left);
            }
            if(cur->right){
                s.push(cur->right);
            }
            
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

//Morris traversal
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        while(root){
            if(root->left){
                TreeNode* pre=root->left;
                while(pre->right && pre->right!=root)
                    pre=pre->right;
                
                if(pre->right==NULL){
                    pre->right=root;
                    root=root->left;
                }
                else{
                    ans.push_back(root->val);
                    pre->right=NULL;
                    root=root->right;
                }
            }
            else{
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};